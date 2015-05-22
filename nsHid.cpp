/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Pierre Phaneuf <pp@ludusdesign.com>
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either of the GNU General Public License Version 2 or later (the "GPL"),
 * or the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


/**
 *
 * A sample of XPConnect. This file contains an implementation nsHid
 * of the interface nsIHid.
 *
 */

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>

#include "hidapi.h"
#include "nsHid.h"
#include "nsMemory.h"

#include "nsEmbedString.h"
#include "nsIClassInfoImpl.h"

// Headers needed for sleeping.
#ifdef _WIN32
	#include <windows.h>
#else
	#include <unistd.h>
#endif
////////////////////////////////////////////////////////////////////////

nsHidImpl::nsHidImpl() : mSerial_number(nsnull)
{
    mSerial_number = (char*)nsMemory::Clone("12345", 6);

}

nsHidImpl::~nsHidImpl()
{
    if (mSerial_number)
        nsMemory::Free(mSerial_number);
}

/**
 * NS_IMPL_ISUPPORTS1 expands to a simple implementation of the nsISupports
 * interface.  This includes a proper implementation of AddRef, Release,
 * and QueryInterface.  If this class supported more interfaces than just
 * nsISupports,
 * you could use NS_IMPL_ADDREF() and NS_IMPL_RELEASE() to take care of the
 * simple stuff, but you would have to create QueryInterface on your own.
 * nsHidFactory.cpp is an example of this approach.
 * Notice that the second parameter to the macro is name of the interface, and
 * NOT the #defined IID.
 *
 * The _CI variant adds support for nsIClassInfo, which permits introspection
 * and interface flattening.
 */
NS_IMPL_CLASSINFO(nsHidImpl, NULL, 0, NS_HID_CID)
NS_IMPL_ISUPPORTS1_CI(nsHidImpl, nsIHid)
/**
 * Notice that in the protoype for this function, the NS_IMETHOD macro was
 * used to declare the return type.  For the implementation, the return
 * type is declared by NS_IMETHODIMP
 */

 static void GetStringValue(nsACString& aValue)
{
    NS_CStringSetData(aValue, "GetSerial_number");
}

  /* readonly attribute char path; */
NS_IMETHODIMP
nsHidImpl::GetPath(char *aPath)
{
    return NS_OK;
}

  /* attribute unsigned short vendor_id; */
NS_IMETHODIMP
nsHidImpl::GetVendor_id(PRUint16 *aVendor_id)
{
    NS_ASSERTION(aVendor_id, "Bad pointer");
    *aVendor_id = VENDOR_ID;

    return NS_OK;
}

/* attribute unsigned short vendor_id; */
NS_IMETHODIMP
nsHidImpl::SetVendor_id(PRUint16 aVendor_id)
{
	mVendorId = aVendor_id;
    return NS_OK;
}

  /* attribute unsigned short product_id; */
NS_IMETHODIMP
nsHidImpl::GetProduct_id(PRUint16 *aProduct_id)
{
    NS_ASSERTION(aProduct_id, "Bad pointer");
    *aProduct_id = PRODUCT_ID;

    return NS_OK;
}

/* attribute unsigned short product_id; */
NS_IMETHODIMP
nsHidImpl::SetProduct_id(PRUint16 aProduct_id)
{
	mProductId = aProduct_id;
    return NS_OK;
}

  /* attribute AString serial_number; */
NS_IMETHODIMP
nsHidImpl::GetSerial_number(char * *aSerial_number)
{
    NS_PRECONDITION(aSerial_number != nsnull, "null ptr");
    if (! aSerial_number)
        return NS_ERROR_NULL_POINTER;

    if (mSerial_number) {
        /**
         * GetValue's job is to return data known by an instance of
         * nsSampleImpl to the outside world.  If we  were to simply return
         * a pointer to data owned by this instance, and the client were to
         * free it, bad things would surely follow.
         * On the other hand, if we create a new copy of the data for our
         * client, and it turns out that client is implemented in JavaScript,
         * there would be no way to free the buffer.  The solution to the
         * buffer ownership problem is the nsMemory singleton.  Any buffer
         * returned by an XPCOM method should be allocated by the nsMemory.
         * This convention lets things like JavaScript reflection do their
         * job, and simplifies the way C++ clients deal with returned buffers.
         */
        *aSerial_number = (char*) nsMemory::Clone(mSerial_number, strlen(mSerial_number) + 1);
        if (! *aSerial_number)
            return NS_ERROR_NULL_POINTER;
    }
    else {
        *aSerial_number = nsnull;
    }
    return NS_OK;
}

/* attribute AString serial_number; */
NS_IMETHODIMP
nsHidImpl::SetSerial_number(const char * aSerial_number)
{
   NS_PRECONDITION(aSerial_number != nsnull, "null ptr");
    if (! aSerial_number)
        return NS_ERROR_NULL_POINTER;

    if (mSerial_number) {
        nsMemory::Free(mSerial_number);
    }

    /**
     * Another buffer passing convention is that buffers passed INTO your
     * object ARE NOT YOURS.  Keep your hands off them, unless they are
     * declared "inout".  If you want to keep the value for posterity,
     * you will have to make a copy of it.
     */
    mSerial_number = (char*) nsMemory::Clone(aSerial_number, strlen(aSerial_number) + 1);
    return NS_OK;
}

  /* readonly attribute unsigned short release_number; */
NS_IMETHODIMP
nsHidImpl::GetRelease_number(PRUint16 *aRelease_number)
{
    return NS_OK;
}

  /* readonly attribute AString manufacturer_string; */
NS_IMETHODIMP
nsHidImpl::GetManufacturer_string(nsAString & aManufacturer_string)
{
	#define MAX_STR 255
	wchar_t  wstr[MAX_STR];
	wstr[0] = 0x0000;
	int res;
	hid_device *handle;
	handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
	if (!handle) {
		printf("unable to open device\n");
    aManufacturer_string.AssignLiteral("unable to open device");
 		return NS_OK;
	}
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	if (res < 0)
	return NS_ERROR_NULL_POINTER;
	printf("Manufacturer String: %ls\n", wstr);
	hid_close(handle);
    aManufacturer_string.Assign(wstr);
    return NS_OK;
}

  /* readonly attribute AString product_string; */
NS_IMETHODIMP
nsHidImpl::GetProduct_string(nsAString & aProduct_string)
{
	#define MAX_STR 255
	PRUnichar  wstr[MAX_STR];
	wstr[0] = 0x0000;
	int res;
	hid_device *handle;
	handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
	if (!handle) {
		printf("unable to open device\n");
    aProduct_string.AssignLiteral("unable to open device");
 		return NS_OK;
	}
	res = hid_get_product_string(handle, wstr, MAX_STR);
	if (res < 0)
	return NS_ERROR_NULL_POINTER;
	printf("Product String: %ls\n", wstr);
	hid_close(handle);
	aProduct_string.Assign(wstr);
    return NS_OK;
}

  /* readonly attribute unsigned short usage_page; */
NS_IMETHODIMP
nsHidImpl::GetUsage_page(PRUint16 *aUsage_page)
{
    return NS_OK;
}

  /* readonly attribute unsigned short usage; */
NS_IMETHODIMP
nsHidImpl::GetUsage(PRUint16 *aUsage)
{
    return NS_OK;
}

/* readonly attribute short interface_number; */
NS_IMETHODIMP
nsHidImpl::GetInterface_number(PRInt16 *aInterface_number)
{
    return NS_OK;
}

// NS_IMETHODIMP
// nsHidImpl::Hid_write(char buf, float *_retval NS_OUTPARAM)
// {
	// memset(buf,0,sizeof(buf));

	//Toggle LED (cmd 0x80). The first byte is the report number (0x1).
	// buf[0] = 0x1;
	// buf[1] = 0x80;
	// res = hid_write(handle, buf, 17);
	// if (res < 0) {
		// printf("Unable to write()\n");
		// printf("Error: %ls\n", hid_error(handle));
	// }
    // return NS_ERROR_NOT_IMPLEMENTED;
// }

NS_IMETHODIMP
nsHidImpl::Hid_read(PRUint8 *a NS_OUTPARAM, PRUint8 *b NS_OUTPARAM, float *_retval NS_OUTPARAM)
{
  int res, i;
  unsigned char buf[256];
	hid_device *handle;
	handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
  if (!handle) {
		printf("unable to open device\n");
    *_retval = -1;
 		return NS_OK;
	}
  hid_set_nonblocking(handle, 1);
	res = 0;
	while (res == 0) {
		res = hid_read(handle, buf, sizeof(buf));
		if (res == 0)
			printf("waiting...\n");
		if (res < 0)
			printf("Unable to read()\n");
		#ifdef WIN32
		Sleep(500);
		#else
		usleep(500*1000);
		#endif
	}
  printf("Data read:\n   ");
	// Print out the returned buffer.
	for (i = 0; i < res; i++)
		printf("%02hhx ", buf[i]);
	printf("\n");
  NS_ASSERTION(a, "bad param");
  NS_ASSERTION(b, "bad param");

  *a = (PRUint8)buf[0];
  *b = (PRUint8)buf[1];
  //*_retval = (char)buf[0];

  hid_close(handle);
  *_retval = res;
	return NS_OK;
}

NS_IMETHODIMP
nsHidImpl::Hid_write(PRUint8 a, PRUint8 b, float *_retval NS_OUTPARAM)
{
	int res;
  unsigned char buf[3];
	hid_device *handle;
	handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
  if (!handle) {
		printf("unable to open device\n");
    *_retval = -1;
 		return NS_OK;
	}
  memset(buf,0,sizeof(buf));
  buf[0] = 0x00;
  buf[1] = a;
  buf[2] = b;
  res = hid_write(handle, buf, 3); //#define USB_CONFIG_HID_TX_SIZE   2
  if (res < 0) {
		printf("Unable to write()\n");
		printf("Error: %ls\n", hid_error(handle));
}
    hid_close(handle);
    *_retval = res;

	return NS_OK;

}