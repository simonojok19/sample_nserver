#ifndef AN_TYPE_5_RECORD_H_INCLUDED
#define AN_TYPE_5_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANFImageBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType5Record, ANFImageBinaryRecord)

#define AN_TYPE_5_RECORD_FIELD_LEN  AN_RECORD_FIELD_LEN
#define AN_TYPE_5_RECORD_FIELD_IDC  AN_RECORD_FIELD_IDC
#define AN_TYPE_5_RECORD_FIELD_IMP  AN_F_IMAGE_BINARY_RECORD_FIELD_IMP
#define AN_TYPE_5_RECORD_FIELD_FGP  AN_F_IMAGE_BINARY_RECORD_FIELD_FGP
#define AN_TYPE_5_RECORD_FIELD_ISR  AN_IMAGE_BINARY_RECORD_FIELD_ISR
#define AN_TYPE_5_RECORD_FIELD_HLL  AN_IMAGE_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_5_RECORD_FIELD_VLL  AN_IMAGE_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_5_RECORD_FIELD_BCA  AN_F_IMAGE_BINARY_RECORD_FIELD_CA
#define AN_TYPE_5_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType5Record instead")
NResult N_API ANType5RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType5Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType5RecordFromNImage instead")
NResult N_API ANType5RecordCreateFromNImage(NVersion_ version, NInt idc, NBool isr, ANBinaryImageCompressionAlgorithm bca,
	HNImage hImage, NUInt flags, HANType5Record * phRecord);

NResult N_API ANType5RecordGetCompressionAlgorithm(HANType5Record hRecord, ANBinaryImageCompressionAlgorithm * pValue);
NResult N_API ANType5RecordGetVendorCompressionAlgorithm(HANType5Record hRecord, NByte * pValue);
NResult N_API ANType5RecordSetCompressionAlgorithm(HANType5Record hRecord, ANBinaryImageCompressionAlgorithm value, NByte vendorValue);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_5_RECORD_H_INCLUDED
