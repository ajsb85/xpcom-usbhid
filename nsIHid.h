/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM nsIHid.idl
 */

#ifndef __gen_nsIHid_h__
#define __gen_nsIHid_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHid */
#define NS_IHID_IID_STR "7cb5b7a1-07d7-11d3-bde2-000064657374"

#define NS_IHID_IID \
  {0x7cb5b7a1, 0x07d7, 0x11d3, \
    { 0xbd, 0xe2, 0x00, 0x00, 0x64, 0x65, 0x73, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIHid : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHID_IID)

  enum { VENDOR_ID = 1240U };

  enum { PRODUCT_ID = 63U };

  /* readonly attribute char path; */
  NS_SCRIPTABLE NS_IMETHOD GetPath(char *aPath) = 0;

  /* attribute unsigned short vendor_id; */
  NS_SCRIPTABLE NS_IMETHOD GetVendor_id(PRUint16 *aVendor_id) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVendor_id(PRUint16 aVendor_id) = 0;

  /* attribute unsigned short product_id; */
  NS_SCRIPTABLE NS_IMETHOD GetProduct_id(PRUint16 *aProduct_id) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetProduct_id(PRUint16 aProduct_id) = 0;

  /* attribute string serial_number; */
  NS_SCRIPTABLE NS_IMETHOD GetSerial_number(char * *aSerial_number) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSerial_number(const char * aSerial_number) = 0;

  /* readonly attribute unsigned short release_number; */
  NS_SCRIPTABLE NS_IMETHOD GetRelease_number(PRUint16 *aRelease_number) = 0;

  /* readonly attribute AString manufacturer_string; */
  NS_SCRIPTABLE NS_IMETHOD GetManufacturer_string(nsAString & aManufacturer_string) = 0;

  /* readonly attribute AString product_string; */
  NS_SCRIPTABLE NS_IMETHOD GetProduct_string(nsAString & aProduct_string) = 0;

  /* readonly attribute unsigned short usage_page; */
  NS_SCRIPTABLE NS_IMETHOD GetUsage_page(PRUint16 *aUsage_page) = 0;

  /* readonly attribute unsigned short usage; */
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint16 *aUsage) = 0;

  /* readonly attribute short interface_number; */
  NS_SCRIPTABLE NS_IMETHOD GetInterface_number(PRInt16 *aInterface_number) = 0;

  /* float hid_write (in octet a, in octet b); */
  NS_SCRIPTABLE NS_IMETHOD Hid_write(PRUint8 a, PRUint8 b, float *_retval NS_OUTPARAM) = 0;

  /* float hid_read (out octet a, out octet b); */
  NS_SCRIPTABLE NS_IMETHOD Hid_read(PRUint8 *a NS_OUTPARAM, PRUint8 *b NS_OUTPARAM, float *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHid, NS_IHID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHID \
  NS_SCRIPTABLE NS_IMETHOD GetPath(char *aPath); \
  NS_SCRIPTABLE NS_IMETHOD GetVendor_id(PRUint16 *aVendor_id); \
  NS_SCRIPTABLE NS_IMETHOD SetVendor_id(PRUint16 aVendor_id); \
  NS_SCRIPTABLE NS_IMETHOD GetProduct_id(PRUint16 *aProduct_id); \
  NS_SCRIPTABLE NS_IMETHOD SetProduct_id(PRUint16 aProduct_id); \
  NS_SCRIPTABLE NS_IMETHOD GetSerial_number(char * *aSerial_number); \
  NS_SCRIPTABLE NS_IMETHOD SetSerial_number(const char * aSerial_number); \
  NS_SCRIPTABLE NS_IMETHOD GetRelease_number(PRUint16 *aRelease_number); \
  NS_SCRIPTABLE NS_IMETHOD GetManufacturer_string(nsAString & aManufacturer_string); \
  NS_SCRIPTABLE NS_IMETHOD GetProduct_string(nsAString & aProduct_string); \
  NS_SCRIPTABLE NS_IMETHOD GetUsage_page(PRUint16 *aUsage_page); \
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint16 *aUsage); \
  NS_SCRIPTABLE NS_IMETHOD GetInterface_number(PRInt16 *aInterface_number); \
  NS_SCRIPTABLE NS_IMETHOD Hid_write(PRUint8 a, PRUint8 b, float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Hid_read(PRUint8 *a NS_OUTPARAM, PRUint8 *b NS_OUTPARAM, float *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHID(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPath(char *aPath) { return _to GetPath(aPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetVendor_id(PRUint16 *aVendor_id) { return _to GetVendor_id(aVendor_id); } \
  NS_SCRIPTABLE NS_IMETHOD SetVendor_id(PRUint16 aVendor_id) { return _to SetVendor_id(aVendor_id); } \
  NS_SCRIPTABLE NS_IMETHOD GetProduct_id(PRUint16 *aProduct_id) { return _to GetProduct_id(aProduct_id); } \
  NS_SCRIPTABLE NS_IMETHOD SetProduct_id(PRUint16 aProduct_id) { return _to SetProduct_id(aProduct_id); } \
  NS_SCRIPTABLE NS_IMETHOD GetSerial_number(char * *aSerial_number) { return _to GetSerial_number(aSerial_number); } \
  NS_SCRIPTABLE NS_IMETHOD SetSerial_number(const char * aSerial_number) { return _to SetSerial_number(aSerial_number); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelease_number(PRUint16 *aRelease_number) { return _to GetRelease_number(aRelease_number); } \
  NS_SCRIPTABLE NS_IMETHOD GetManufacturer_string(nsAString & aManufacturer_string) { return _to GetManufacturer_string(aManufacturer_string); } \
  NS_SCRIPTABLE NS_IMETHOD GetProduct_string(nsAString & aProduct_string) { return _to GetProduct_string(aProduct_string); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsage_page(PRUint16 *aUsage_page) { return _to GetUsage_page(aUsage_page); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint16 *aUsage) { return _to GetUsage(aUsage); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterface_number(PRInt16 *aInterface_number) { return _to GetInterface_number(aInterface_number); } \
  NS_SCRIPTABLE NS_IMETHOD Hid_write(PRUint8 a, PRUint8 b, float *_retval NS_OUTPARAM) { return _to Hid_write(a, b, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Hid_read(PRUint8 *a NS_OUTPARAM, PRUint8 *b NS_OUTPARAM, float *_retval NS_OUTPARAM) { return _to Hid_read(a, b, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHID(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPath(char *aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_SCRIPTABLE NS_IMETHOD GetVendor_id(PRUint16 *aVendor_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendor_id(aVendor_id); } \
  NS_SCRIPTABLE NS_IMETHOD SetVendor_id(PRUint16 aVendor_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVendor_id(aVendor_id); } \
  NS_SCRIPTABLE NS_IMETHOD GetProduct_id(PRUint16 *aProduct_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProduct_id(aProduct_id); } \
  NS_SCRIPTABLE NS_IMETHOD SetProduct_id(PRUint16 aProduct_id) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProduct_id(aProduct_id); } \
  NS_SCRIPTABLE NS_IMETHOD GetSerial_number(char * *aSerial_number) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSerial_number(aSerial_number); } \
  NS_SCRIPTABLE NS_IMETHOD SetSerial_number(const char * aSerial_number) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSerial_number(aSerial_number); } \
  NS_SCRIPTABLE NS_IMETHOD GetRelease_number(PRUint16 *aRelease_number) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelease_number(aRelease_number); } \
  NS_SCRIPTABLE NS_IMETHOD GetManufacturer_string(nsAString & aManufacturer_string) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManufacturer_string(aManufacturer_string); } \
  NS_SCRIPTABLE NS_IMETHOD GetProduct_string(nsAString & aProduct_string) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProduct_string(aProduct_string); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsage_page(PRUint16 *aUsage_page) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsage_page(aUsage_page); } \
  NS_SCRIPTABLE NS_IMETHOD GetUsage(PRUint16 *aUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsage(aUsage); } \
  NS_SCRIPTABLE NS_IMETHOD GetInterface_number(PRInt16 *aInterface_number) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInterface_number(aInterface_number); } \
  NS_SCRIPTABLE NS_IMETHOD Hid_write(PRUint8 a, PRUint8 b, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Hid_write(a, b, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Hid_read(PRUint8 *a NS_OUTPARAM, PRUint8 *b NS_OUTPARAM, float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Hid_read(a, b, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHid : public nsIHid
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHID

  nsHid();

private:
  ~nsHid();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHid, nsIHid)

nsHid::nsHid()
{
  /* member initializers and constructor code */
}

nsHid::~nsHid()
{
  /* destructor code */
}

/* readonly attribute char path; */
NS_IMETHODIMP nsHid::GetPath(char *aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short vendor_id; */
NS_IMETHODIMP nsHid::GetVendor_id(PRUint16 *aVendor_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHid::SetVendor_id(PRUint16 aVendor_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short product_id; */
NS_IMETHODIMP nsHid::GetProduct_id(PRUint16 *aProduct_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHid::SetProduct_id(PRUint16 aProduct_id)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute string serial_number; */
NS_IMETHODIMP nsHid::GetSerial_number(char * *aSerial_number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHid::SetSerial_number(const char * aSerial_number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short release_number; */
NS_IMETHODIMP nsHid::GetRelease_number(PRUint16 *aRelease_number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString manufacturer_string; */
NS_IMETHODIMP nsHid::GetManufacturer_string(nsAString & aManufacturer_string)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString product_string; */
NS_IMETHODIMP nsHid::GetProduct_string(nsAString & aProduct_string)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short usage_page; */
NS_IMETHODIMP nsHid::GetUsage_page(PRUint16 *aUsage_page)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short usage; */
NS_IMETHODIMP nsHid::GetUsage(PRUint16 *aUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short interface_number; */
NS_IMETHODIMP nsHid::GetInterface_number(PRInt16 *aInterface_number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float hid_write (in octet a, in octet b); */
NS_IMETHODIMP nsHid::Hid_write(PRUint8 a, PRUint8 b, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float hid_read (out octet a, out octet b); */
NS_IMETHODIMP nsHid::Hid_read(PRUint8 *a NS_OUTPARAM, PRUint8 *b NS_OUTPARAM, float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHid_h__ */
