#ifndef AN_TYPE_7_RECORD_H_INCLUDED
#define AN_TYPE_7_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANBinaryRecord.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType7Record, ANBinaryRecord)

#define AN_TYPE_7_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_7_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC
#define AN_TYPE_7_RECORD_FIELD_UDF AN_RECORD_FIELD_DATA

#define AN_TYPE_7_RECORD_FIELD_UDF_FROM  (AN_TYPE_7_RECORD_FIELD_IDC + 1)
#define AN_TYPE_7_RECORD_FIELD_UDF_TO    AN_RECORD_MAX_FIELD_NUMBER

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType7Record instead")
NResult N_API ANType7RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType7Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType7Record instead")
NResult N_API ANType7RecordCreateEx(NUInt flags, HANType7Record * phRecord);

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_7_RECORD_H_INCLUDED
