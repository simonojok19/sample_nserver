#ifndef AN_TYPE_4_RECORD_H_INCLUDED
#define AN_TYPE_4_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANFImageBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType4Record, ANFImageBinaryRecord)

#define AN_TYPE_4_RECORD_FIELD_LEN  AN_RECORD_FIELD_LEN
#define AN_TYPE_4_RECORD_FIELD_IDC  AN_RECORD_FIELD_IDC
#define AN_TYPE_4_RECORD_FIELD_IMP  AN_F_IMAGE_BINARY_RECORD_FIELD_IMP
#define AN_TYPE_4_RECORD_FIELD_FGP  AN_F_IMAGE_BINARY_RECORD_FIELD_FGP
#define AN_TYPE_4_RECORD_FIELD_ISR  AN_IMAGE_BINARY_RECORD_FIELD_ISR
#define AN_TYPE_4_RECORD_FIELD_HLL  AN_IMAGE_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_4_RECORD_FIELD_VLL  AN_IMAGE_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_4_RECORD_FIELD_GCA  AN_F_IMAGE_BINARY_RECORD_FIELD_CA
#define AN_TYPE_4_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType4Record instead")
NResult N_API ANType4RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType4Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType4Record instead")
NResult N_API ANType4RecordCreateEx(NUInt flags, HANType4Record * phRecord);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType4RecordFromNImage instead")
NResult N_API ANType4RecordCreateFromNImage(NVersion_ version, NInt idc, NBool isr, ANImageCompressionAlgorithm ca,
		HNImage hImage, NUInt flags, HANType4Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType4RecordFromNImage instead")
NResult N_API ANType4RecordCreateFromNImageEx(NBool isr, ANImageCompressionAlgorithm ca, HNImage hImage, NUInt flags, HANType4Record * phRecord);

NResult N_API ANType4RecordGetCompressionAlgorithm(HANType4Record hRecord, ANImageCompressionAlgorithm * pValue);
NResult N_API ANType4RecordGetVendorCompressionAlgorithm(HANType4Record hRecord, NByte * pValue);
NResult N_API ANType4RecordSetCompressionAlgorithm(HANType4Record hRecord, ANImageCompressionAlgorithm value, NByte vendorValue);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_4_RECORD_H_INCLUDED
