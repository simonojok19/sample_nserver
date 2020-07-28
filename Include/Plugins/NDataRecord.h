#ifndef N_DATA_RECORD_H_INCLUDED
#define N_DATA_RECORD_H_INCLUDED

#include <Core/NObject.h>
#include <Core/NTimeSpan.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NDataRecord, NObject)

NResult N_API NDataRecordGetId(HNDataRecord hRecord, HNString * phValue);
NResult N_API NDataRecordGetDataSize(HNDataRecord hRecord, NSizeType * pValue);
NResult N_API NDataRecordGetVersion(HNDataRecord hRecord, NVersion_ * pValue);
NResult N_API NDataRecordGetLoadTime(HNDataRecord hRecord, NTimeSpan_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !N_DATA_RECORD_H_INCLUDED
