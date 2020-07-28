#ifndef II_RECORD_H_INCLUDED
#define II_RECORD_H_INCLUDED

#include <Biometrics/Standards/BdifTypes.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(IIRecord, NObject)

#ifdef N_CPP
}
#endif

#include <Biometrics/Standards/IirIrisImage.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum IirIrisOcclusions_
{
	iirioUndefined = 0,
	iirioProcessed = 1
} IirIrisOcclusions;

N_DECLARE_TYPE(IirIrisOcclusions)

typedef enum IirIrisOcclusionFilling_
{
	iiriofZero = 0,
	iiriofUnit = 1
} IirIrisOcclusionFilling;

N_DECLARE_TYPE(IirIrisOcclusionFilling)

typedef enum IirIrisBoundary_
{
	iiribUndefined = 0,
	iiribProcessed = 1
} IirIrisBoundary;

N_DECLARE_TYPE(IirIrisBoundary)

typedef enum IirImageTransformation_
{
	iiritUndefined = 0,
	iiritStandard = 1
} IirImageTransformation;

N_DECLARE_TYPE(IirImageTransformation)

#define IIR_VERSION_ANSI_1_0 0x0100
#define IIR_VERSION_ISO_1_0  0x0100
#define IIR_VERSION_ISO_2_0  0x0200

#define IIR_VERSION_ANSI_CURRENT IIR_VERSION_ANSI_1_0
#define IIR_VERSION_ISO_CURRENT  IIR_VERSION_ISO_2_0

#define IIR_RANGE_UNASSIGNED 0
#define IIR_RANGE_FAILED 1
#define IIR_RANGE_OVERFLOW 0xFFFF

#define IIR_MAX_IRIS_IMAGE_COUNT_PER_IRIS_1_0 N_USHORT_MAX
#define IIR_MAX_IRIS_IMAGE_COUNT_1_0          (2 * IIR_MAX_IRIS_IMAGE_COUNT_PER_IRIS_1_0)
#define IIR_MAX_IRIS_IMAGE_COUNT_2_0          N_USHORT_MAX

#define IIR_PROCESS_IRIS_FIRST_IRIS_IMAGE_ONLY 0x00001000

NResult N_API IIRecordCreateEx2(BdifStandard standard, NVersion_ version, NUInt flags, HIIRecord * phRecord);
NResult N_API IIRecordCreateFromMemoryN(HNBuffer hBuffer, NUInt flags, BdifStandard standard, NSizeType * pSize, HIIRecord * phRecord);
NResult N_API IIRecordCreateFromMemory(const void * pBuffer, NSizeType bufferSize, NUInt flags, BdifStandard standard, NSizeType * pSize, HIIRecord * phRecord);
NResult N_API IIRecordCreateFromIIRecordEx(HIIRecord hSrcRecord, NUInt flags, BdifStandard standard, NVersion_ version, HIIRecord * phRecord);

NResult N_API IIRecordCreateFromNImageEx(HNImage hImage, IirImageFormat imageFormat, BdifEyePosition irisPosition, NUInt flags, BdifStandard standard, NVersion_ version, HIIRecord * phRecord);
NResult N_API IIRecordCreateFromImageDataN(BdifStandard standard, NVersion_ version, BdifEyePosition irisPosition, HNBuffer hImageBuffer, HIIRecord * phRecord);

NResult N_API IIRecordAddIrisImage(HIIRecord hRecord, HIirIrisImage * phIrisImage);
NResult N_API IIRecordAddIrisImageFromNImage(HIIRecord hRecord, IirImageFormat imageFormat, BdifEyePosition irisPosition, HNImage hImage, HIirIrisImage * phIrisImage);
NResult N_API IIRecordAddIrisImageFromImageDataN(HIIRecord hRecord, BdifEyePosition irisPosition, HNBuffer hImageBuffer, HIirIrisImage * phIrisImage);

NResult N_API IIRecordGetIrisImageCount(HIIRecord hRecord, NInt * pValue);
NResult N_API IIRecordGetIrisImage(HIIRecord hRecord, NInt index, HIirIrisImage * phValue);
NResult N_API IIRecordGetIrisImageCapacity(HIIRecord hRecord, NInt * pValue);
NResult N_API IIRecordSetIrisImageCapacity(HIIRecord hRecord, NInt value);
N_DEPRECATED("function is deprecated, use IIRecordAddIrisImage/IIRecordAddIrisImageFromImageDataN/IIRecordAddIrisImageFromNImage instead")
NResult N_API IIRecordAddIrisImageEx(HIIRecord hRecord, HIirIrisImage hIrisImage, NInt * pIndex);
NResult N_API IIRecordRemoveIrisImageAt(HIIRecord hRecord, NInt index);
NResult N_API IIRecordClearIrisImages(HIIRecord hRecord);

NResult N_API IIRecordGetStandard(HIIRecord hRecord, BdifStandard * pValue);
NResult N_API IIRecordGetVersion(HIIRecord hRecord, NVersion_ * pValue);
NResult N_API IIRecordGetCbeffProductId(HIIRecord hRecord, NUInt * pValue);
NResult N_API IIRecordSetCbeffProductId(HIIRecord hRecord, NUInt value);
NResult N_API IIRecordGetCaptureDeviceId(HIIRecord hRecord, NUShort * pValue);
NResult N_API IIRecordSetCaptureDeviceId(HIIRecord hRecord, NUShort value);
NResult N_API IIRecordGetIrisHorzOrientation(HIIRecord hRecord, BdifIrisOrientation * pValue);
NResult N_API IIRecordSetIrisHorzOrientation(HIIRecord hRecord, BdifIrisOrientation value);
NResult N_API IIRecordGetIrisVertOrientation(HIIRecord hRecord, BdifIrisOrientation * pValue);
NResult N_API IIRecordSetIrisVertOrientation(HIIRecord hRecord, BdifIrisOrientation value);
NResult N_API IIRecordGetIrisScanType(HIIRecord hRecord, BdifIrisScanType * pValue);
NResult N_API IIRecordSetIrisScanType(HIIRecord hRecord, BdifIrisScanType value);
NResult N_API IIRecordGetIrisOcclusions(HIIRecord hRecord, IirIrisOcclusions * pValue);
NResult N_API IIRecordSetIrisOcclusions(HIIRecord hRecord, IirIrisOcclusions value);
NResult N_API IIRecordGetIrisOcclusionFilling(HIIRecord hRecord, IirIrisOcclusionFilling * pValue);
NResult N_API IIRecordSetIrisOcclusionFilling(HIIRecord hRecord, IirIrisOcclusionFilling value);
NResult N_API IIRecordGetIrisBoundaryExtraction(HIIRecord hRecord, IirIrisBoundary * pValue);
NResult N_API IIRecordSetIrisBoundaryExtraction(HIIRecord hRecord, IirIrisBoundary value);
NResult N_API IIRecordGetIrisDiameter(HIIRecord hRecord, NUShort * pValue);
NResult N_API IIRecordSetIrisDiameter(HIIRecord hRecord, NUShort value);
NResult N_API IIRecordGetImageFormat(HIIRecord hRecord, IirImageFormat * pValue);
NResult N_API IIRecordSetImageFormat(HIIRecord hRecord, IirImageFormat value);
NResult N_API IIRecordGetRawImageWidth(HIIRecord hRecord, NUShort * pValue);
NResult N_API IIRecordSetRawImageWidth(HIIRecord hRecord, NUShort value);
NResult N_API IIRecordGetRawImageHeight(HIIRecord hRecord, NUShort * pValue);
NResult N_API IIRecordSetRawImageHeight(HIIRecord hRecord, NUShort value);
NResult N_API IIRecordGetIntensityDepth(HIIRecord hRecord, NByte * pValue);
NResult N_API IIRecordSetIntensityDepth(HIIRecord hRecord, NByte value);
NResult N_API IIRecordGetImageTransformation(HIIRecord hRecord, IirImageTransformation * pValue);
NResult N_API IIRecordSetImageTransformation(HIIRecord hRecord, IirImageTransformation value);

NResult N_API IIRecordGetDeviceUniqueIdentifierN(HIIRecord hRecord, HNString * phValue);

NResult N_API IIRecordSetDeviceUniqueIdentifierN(HIIRecord hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API IIRecordSetDeviceUniqueIdentifierA(HIIRecord hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API IIRecordSetDeviceUniqueIdentifierW(HIIRecord hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API IIRecordSetDeviceUniqueIdentifier(HIIRecord hRecord, const NChar * szValue);
#endif
#define IIRecordSetDeviceUniqueIdentifier N_FUNC_AW(IIRecordSetDeviceUniqueIdentifier)

NResult N_API IIRecordGetGuid(HIIRecord hRecord, struct NGuid_ * pValue);
NResult N_API IIRecordSetGuid(HIIRecord hRecord, const struct NGuid_ * pValue);

#ifdef N_CPP
}
#endif

#endif // !II_RECORD_H_INCLUDED
