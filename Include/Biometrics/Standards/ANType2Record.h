#ifndef AN_TYPE_2_RECORD_H_INCLUDED
#define AN_TYPE_2_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANAsciiRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType2Record, ANAsciiRecord)

#define AN_TYPE_2_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_2_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_2_RECORD_FIELD_UDF_FROM  (AN_TYPE_2_RECORD_FIELD_IDC + 1)
#define AN_TYPE_2_RECORD_FIELD_UDF_TO    AN_RECORD_MAX_FIELD_NUMBER
#define AN_TYPE_2_RECORD_FIELD_UDF_TO_V4 AN_ASCII_RECORD_MAX_FIELD_NUMBER

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType2Record instead")
NResult N_API ANType2RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType2Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType2Record instead")
NResult N_API ANType2RecordCreateEx(NUInt flags, HANType2Record * phRecord);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_2_RECORD_H_INCLUDED
