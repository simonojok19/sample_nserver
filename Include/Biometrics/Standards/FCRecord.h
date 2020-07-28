#ifndef FC_RECORD_H_INCLUDED
#define FC_RECORD_H_INCLUDED

#include <Biometrics/Standards/BdifTypes.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(FCRecord, NObject)

#ifdef N_CPP
}
#endif

#include <Biometrics/Standards/FcrFaceImage.h>

#ifdef N_CPP
extern "C"
{
#endif

#define FCR_VERSION_ANSI_1_0 0x0100
#define FCR_VERSION_ISO_1_0  0x0100
#define FCR_VERSION_ISO_3_0  0x0300

#define FCR_VERSION_ANSI_CURRENT FCR_VERSION_ANSI_1_0
#define FCR_VERSION_ISO_CURRENT  FCR_VERSION_ISO_3_0

#define FCR_MAX_FACE_IMAGE_COUNT N_USHORT_MAX

#define FCR_PROCESS_FIRST_FACE_IMAGE_ONLY 0x00000100

NResult N_API FCRecordCreateEx(BdifStandard standard, NVersion_ version, NUInt flags, HFCRecord * phRecord);
NResult N_API FCRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, BdifStandard standard, NSizeType * pSize, HFCRecord * phRecord);
NResult N_API FCRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, BdifStandard standard, NSizeType * pSize, HFCRecord * phRecord);
NResult N_API FCRecordCreateFromFCRecordEx(HFCRecord hSrcRecord, NUInt flags, BdifStandard standard, NVersion_ version, HFCRecord * phRecord);

NResult N_API FCRecordCreateFromNImageEx(HNImage hImage, FcrFaceImageType faceImageType, FcrImageDataType imageDataType, NUInt flags, BdifStandard standard, NVersion_ version, HFCRecord * phRecord);
NResult N_API FCRecordCreateFromImageDataN(BdifStandard standard, NVersion_ version, FcrFaceImageType faceImageType, HNBuffer hImageBuffer, NUInt flags, HFCRecord * phRecord);

NResult N_API FCRecordGetVersion(HFCRecord hRecord, NVersion_ * pValue);
NResult N_API FCRecordGetStandard(HFCRecord hRecord, BdifStandard * pValue);
NResult N_API FCRecordGetCertificationFlag(HFCRecord hRecord, NBool * pValue);
NResult N_API FCRecordGetTemporalSemantics(HFCRecord hRecord, BdifFaceTemporalSemantics * pValue);
NResult N_API FCRecordGetTemporalSemanticsInMilliseconds(HFCRecord hRecord, NUShort * pValue);
NResult N_API FCRecordSetTemporalSemantics(HFCRecord hRecord, BdifFaceTemporalSemantics value, NUShort valueInMilliseconds);

NResult N_API FCRecordAddFaceImage(HFCRecord hRecord, NUInt flags, HFcrFaceImage * phFaceImage);
NResult N_API FCRecordAddFaceImageFromNImage(HFCRecord hRecord, FcrFaceImageType faceImageType, FcrImageDataType imageDataType, HNImage hImage, NUInt flags, HFcrFaceImage * phFaceImage);
NResult N_API FCRecordAddFaceImageFromImageDataN(HFCRecord hRecord, FcrFaceImageType faceImageType, HNBuffer hImageBuffer, NUInt flags, HFcrFaceImage * phFaceImage);

N_DEPRECATED("function is deprecated, use FCRecordAddFaceImage/FCRecordAddFaceImageFromImageDataN/FCRecordAddFaceImageFromNImage instead")
NResult N_API FCRecordAddFaceImageEx(HFCRecord hRecord, HFcrFaceImage hFaceImage, NInt * pIndex);
NResult N_API FCRecordGetFaceImageCount(HFCRecord hRecord, NInt * pValue);
NResult N_API FCRecordGetFaceImage(HFCRecord hRecord, NInt index, HFcrFaceImage * phValue);
NResult N_API FCRecordGetFaceImageCapacity(HFCRecord hRecord, NInt * pValue);
NResult N_API FCRecordSetFaceImageCapacity(HFCRecord hRecord, NInt value);
NResult N_API FCRecordRemoveFaceImageAt(HFCRecord hRecord, NInt index);
NResult N_API FCRecordClearFaceImages(HFCRecord hRecord);

#ifdef N_CPP
}
#endif

#endif // !FC_RECORD_H_INCLUDED
