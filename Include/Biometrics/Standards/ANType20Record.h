#ifndef AN_TYPE_20_RECORD_H_INCLUDED
#define AN_TYPE_20_RECORD_H_INCLUDED

#include <Biometrics/Standards/ANImageAsciiBinaryRecord.h>
#include <Geometry/NGeometry.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(ANType20Record, ANImageAsciiBinaryRecord)

#define AN_TYPE_20_RECORD_FIELD_LEN AN_RECORD_FIELD_LEN
#define AN_TYPE_20_RECORD_FIELD_IDC AN_RECORD_FIELD_IDC

#define AN_TYPE_20_RECORD_FIELD_CAR 3

#define AN_TYPE_20_RECORD_FIELD_SRC AN_ASCII_BINARY_RECORD_FIELD_SRC
#define AN_TYPE_20_RECORD_FIELD_SRD AN_ASCII_BINARY_RECORD_FIELD_DAT
#define AN_TYPE_20_RECORD_FIELD_HLL AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL
#define AN_TYPE_20_RECORD_FIELD_VLL AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL
#define AN_TYPE_20_RECORD_FIELD_SLC AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC
#define AN_TYPE_20_RECORD_FIELD_THPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS
#define AN_TYPE_20_RECORD_FIELD_TVPS AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS
#define AN_TYPE_20_RECORD_FIELD_CGA AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA
#define AN_TYPE_20_RECORD_FIELD_BPX AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX
#define AN_TYPE_20_RECORD_FIELD_CSP AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CSP

#define AN_TYPE_20_RECORD_FIELD_AQS  14
#define AN_TYPE_20_RECORD_FIELD_SFT  15
#define AN_TYPE_20_RECORD_FIELD_SEG  16
#define AN_TYPE_20_RECORD_FIELD_SHPS 17
#define AN_TYPE_20_RECORD_FIELD_SVPS 18
#define AN_TYPE_20_RECORD_FIELD_TIX  19

#define AN_TYPE_20_RECORD_FIELD_COM AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM

#define AN_TYPE_20_RECORD_FIELD_SRN 21
#define AN_TYPE_20_RECORD_FIELD_ICDR 22

#define AN_TYPE_20_RECORD_FIELD_ANN AN_ASCII_BINARY_RECORD_FIELD_ANN
#define AN_TYPE_20_RECORD_FIELD_DUI AN_ASCII_BINARY_RECORD_FIELD_DUI
#define AN_TYPE_20_RECORD_FIELD_MMS AN_ASCII_BINARY_RECORD_FIELD_MMS

#define AN_TYPE_20_RECORD_FIELD_SAN AN_ASCII_BINARY_RECORD_FIELD_SAN
#define AN_TYPE_20_RECORD_FIELD_EFR AN_ASCII_BINARY_RECORD_FIELD_EFR
#define AN_TYPE_20_RECORD_FIELD_ASC AN_ASCII_BINARY_RECORD_FIELD_ASC
#define AN_TYPE_20_RECORD_FIELD_HAS AN_ASCII_BINARY_RECORD_FIELD_HAS
#define AN_TYPE_20_RECORD_FIELD_GEO AN_ASCII_BINARY_RECORD_FIELD_GEO

#define AN_TYPE_20_RECORD_FIELD_UDF_FROM AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM
#define AN_TYPE_20_RECORD_FIELD_UDF_TO_V5 AN_ASCII_BINARY_RECORD_FIELD_UDF_TO_V5

#define AN_TYPE_20_RECORD_FIELD_DATA AN_RECORD_FIELD_DATA

#define AN_TYPE_20_RECORD_MAX_ACQUISITION_SOURCE_COUNT 9

#define AN_TYPE_20_RECORD_MIN_SEGMENT_COUNT 1
#define AN_TYPE_20_RECORD_MAX_SEGMENT_COUNT 99
#define AN_TYPE_20_RECORD_MIN_SEGMENT_VERTEX_COUNT 3
#define AN_TYPE_20_RECORD_MAX_SEGMENT_VERTEX_COUNT 99
#define AN_TYPE_20_RECORD_MIN_SEGMENT_INTERNAL_FILE_POINTER_LENGTH 1
#define AN_TYPE_20_RECORD_MAX_SEGMENT_INTERNAL_FILE_POINTER_LENGTH 15

#define AN_TYPE_20_RECORD_MIN_AQS_ANALOG_TO_DIGITAL_CONVERSION_LENGTH 1
#define AN_TYPE_20_RECORD_MAX_AQS_ANALOG_TO_DIGITAL_CONVERSION_LENGTH 200
#define AN_TYPE_20_RECORD_MIN_AQS_RADIO_TRANSMISSION_FORMAT_LENGTH    1
#define AN_TYPE_20_RECORD_MAX_AQS_RADIO_TRANSMISSION_FORMAT_LENGTH    200
#define AN_TYPE_20_RECORD_MIN_AQS_SPECIAL_CHARACTERISTICS_LENGTH      1
#define AN_TYPE_20_RECORD_MAX_AQS_SPECIAL_CHARACTERISTICS_LENGTH      200

#define AN_TYPE_20_RECORD_MIN_REPRESENTATION_NUMBER  1
#define AN_TYPE_20_RECORD_MAX_REPRESENTATION_NUMBER  255
#define AN_TYPE_20_RECORD_REPRESENTATION_LENGTH      3

typedef enum ANSrnCardinality_
{
	ansrnUnspecified = 0,
	ansrncOneToOne = 1,
	ansrncOneToMany = 2,
	ansrncManyToMany = 3
} ANSrnCardinality;

N_DECLARE_TYPE(ANSrnCardinality)

typedef enum ANAcquisitionSourceType_
{
	anastUnspecified = 0,
	anastStaticDigitalImageFromUnknownSource = 1,
	anastStaticDigitalImageFromDigitalCamera = 2,
	anastStaticDigitalImageFromScanner = 3,
	anastSingleVideoFrameFromUnknownSource = 4,
	anastSingleVideoFrameFromAnalogCamera = 5,
	anastSingleVideoFrameFromDigitalCamera = 6,
	anastVideoSequenceFromUnknownSource = 7,
	anastVideoSequenceFromAnalogCameraInAnalogFormat = 8,
	anastVideoSequenceFromAnalogSourceInDigitalFormat = 9,
	anastVideoSequenceFromDigitalCamera = 10,
	anastComputerScreenImageCapture = 11,
	anastAnalogAudioRecordingDeviceInAnalogForm = 12,
	anastAnalogAudioRecordingDeviceInDigitalForm = 13,
	anastDigitalAudioRecordingDevice = 14,
	anastLandlineTelephoneBothSenderAndReceiver = 15,
	anastMobileTelephoneBothSenderAndReceiver = 16,
	anastSatelliteTelephoneBothSenderAndReceiver = 17,
	anastTelephoneUnknownOrMixedSource = 18,
	anastTelevisionNstc = 19,
	anastTelevisionPal = 20,
	anastTelevisionOther = 21,
	anastVoip = 22,
	anastRadioTransmissionShortWave = 23,
	anastRadioTransmissionAmateurRadio = 24,
	anastRadioTransmissionFm = 25,
	anastRadioTransmissionLongWave = 26,
	anastRadioTransmissionAm = 27,
	anastRadioTransmissionAircraftFrequencies = 28,
	anastRadioTransmissionShipAndCoastalStationFrequencies = 29,
	anastVendorSpecificCaptureFormat = 30,
	anastOther = 31
} ANAcquisitionSourceType;

N_DECLARE_TYPE(ANAcquisitionSourceType)

struct ANAcquisitionSource_
{
	ANAcquisitionSourceType acquisitionSourceType;
	HNString hAnalogToDigital;
	HNString hRadioTransmissionFormat;
	HNString hSpecialCharacteristics;
};
#ifndef AN_TYPE_20_RECORD_HPP_INCLUDED
typedef struct ANAcquisitionSource_ ANAcquisitionSource;
#endif

N_DECLARE_TYPE(ANAcquisitionSource)

NResult N_API ANAcquisitionSourceCreateN(ANAcquisitionSourceType acquisitionSourceType, HNString hAnalogToDigital, HNString hRadioTransmissionFormat, HNString hSpecialCharacteristics, struct ANAcquisitionSource_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANAcquisitionSourceCreateA(ANAcquisitionSourceType acquisitionSourceType, const NAChar * szAnalogToDigital, const NAChar * hszRadioTransmissionFormat, const NAChar * szSpecialCharacteristics, struct ANAcquisitionSource_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANAcquisitionSourceCreateW(ANAcquisitionSourceType acquisitionSourceType, const NWChar * szAnalogToDigital, const NWChar * hszRadioTransmissionFormat, const NWChar * szSpecialCharacteristics, struct ANAcquisitionSource_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANAcquisitionSourceCreate(ANAcquisitionSourceType acquisitionSourceType, const NChar * szAnalogToDigital, const NChar * hszRadioTransmissionFormat, const NChar * szSpecialCharacteristics, struct ANAcquisitionSource_ * pValue);
#endif
#define ANAcquisitionSourceCreate N_FUNC_AW(ANAcquisitionSourceCreate)

NResult N_API ANAcquisitionSourceDispose(struct ANAcquisitionSource_ * pValue);
NResult N_API ANAcquisitionSourceCopy(const struct ANAcquisitionSource_ * pSrcValue, struct ANAcquisitionSource_ * pDstValue);
NResult N_API ANAcquisitionSourceSet(const struct ANAcquisitionSource_ * pSrcValue, struct ANAcquisitionSource_ * pDstValue);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20Record instead")
NResult N_API ANType20RecordCreate(NVersion_ version, NInt idc, NUInt flags, HANType20Record * phRecord);
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20Record instead")
NResult N_API ANType20RecordCreateEx(NUInt flags, HANType20Record * phRecord);

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20RecordFromNImageN instead")
NResult N_API ANType20RecordCreateFromNImageN(NVersion_ version, NInt idc, NUInt representationNumber, HNString hSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType20Record * phRecord);
#ifndef N_NO_ANSI_FUNC
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20RecordFromNImageA instead")
NResult ANType20RecordCreateFromNImageA(NVersion_ version, NInt idc, NUInt representationNumber, const NAChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType20Record * phRecord);
#endif
#ifndef N_NO_UNICODE
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20RecordFromNImageW instead")
NResult ANType20RecordCreateFromNImageW(NVersion_ version, NInt idc, NUInt representationNumber, const NWChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType20Record * phRecord);
#endif
#ifdef N_DOCUMENTATION
N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20RecordFromNImage instead")
NResult ANType20RecordCreateFromNImage(NVersion_ version, NInt idc, NUInt representationNumber, const NChar * szSrc, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, HNImage hImage, NUInt flags, HANType20Record * phRecord);
#endif
#define ANType20RecordCreateFromNImage N_FUNC_AW(ANType20RecordCreateFromNImage)

N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and ANTemplateAddType20RecordFromNImageN instead")
NResult N_API ANType20RecordCreateFromNImageNEx(NUInt representationNumber, HNString hSrc, BdifScaleUnits slc, ANImageCompressionAlgorithm cga,
												HNImage hImage, NUInt flags, HANType20Record * phRecord);

NResult N_API ANType20RecordGetSrnCardinality(HANType20Record hRecord, ANSrnCardinality * pValue);
NResult N_API ANType20RecordSetSrnCardinality(HANType20Record hRecord, ANSrnCardinality value);

NResult N_API ANType20RecordGetAcquisitionSourceCount(HANType20Record hRecord, NInt * pValue);
NResult N_API ANType20RecordGetAcquisitionSource(HANType20Record hRecord, NInt index, struct ANAcquisitionSource_ * pValue);
NResult N_API ANType20RecordGetAcquisitionSourceCapacity(HANType20Record hRecord, NInt * pValue);
NResult N_API ANType20RecordSetAcquisitionSourceCapacity(HANType20Record hRecord, NInt value);
NResult N_API ANType20RecordGetAcquisitionSources(HANType20Record hRecord, struct ANAcquisitionSource_ * * parValues, NInt * pValueCount);
NResult N_API ANType20RecordSetAcquisitionSource(HANType20Record hRecord, NInt index, const struct ANAcquisitionSource_ * pValue);
NResult N_API ANType20RecordAddAcquisitionSource(HANType20Record hRecord, const struct ANAcquisitionSource_ * pValue, NInt * pIndex);
NResult N_API ANType20RecordInsertAcquisitionSource(HANType20Record hRecord, NInt index, const struct ANAcquisitionSource_ * pValue);
NResult N_API ANType20RecordRemoveAcquisitionSourceAt(HANType20Record hRecord, NInt index);
NResult N_API ANType20RecordClearAcquisitionSources(HANType20Record hRecord);

NResult N_API ANType20RecordGetSourceRepresentationFormat(HANType20Record hRecord, struct ANFileFormat_ * pValue, NBool * pHasValue);
NResult N_API ANType20RecordGetSourceRepresentationFormatFileTypeN(HANType20Record hRecord, HNString * phValue);
NResult N_API ANType20RecordGetSourceRepresentationFormatDecodingInstructionsN(HANType20Record hRecord, HNString * phValue);
NResult N_API ANType20RecordSetSourceRepresentationFormatEx(HANType20Record hRecord, const struct ANFileFormat_ * pValue);

NResult N_API ANType20RecordSetSourceRepresentationFormatN(HANType20Record hRecord, HNString hFileType, HNString hDecodingInstructions);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType20RecordSetSourceRepresentationFormatA(HANType20Record hRecord, const NAChar * szFileType, const NAChar * szDecodingInstructions);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType20RecordSetSourceRepresentationFormatW(HANType20Record hRecord, const NWChar * szFileType, const NWChar * szDecodingInstructions);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType20RecordSetSourceRepresentationFormat(HANType20Record hRecord, const NChar * szFileType, const NChar * szDecodingInstructions);
#endif
#define ANType20RecordSetSourceRepresentationFormat N_FUNC_AW(ANType20RecordSetSourceRepresentationFormat)


NResult N_API ANType20RecordGetSegmentCount(HANType20Record hRecord, NInt * pValue);
NResult N_API ANType20RecordGetSegment(HANType20Record hRecord, NInt index, struct ANSegment_ * pValue);
NResult N_API ANType20RecordGetSegmentCapacity(HANType20Record hRecord, NInt * pValue);
NResult N_API ANType20RecordSetSegmentCapacity(HANType20Record hRecord, NInt value);
NResult N_API ANType20RecordGetSegments(HANType20Record hRecord, struct ANSegment_ * * parValues, NInt * pValueCount);
NResult N_API ANType20RecordSetSegment(HANType20Record hRecord, NInt index, const struct ANSegment_ * pValue);
NResult N_API ANType20RecordAddSegment(HANType20Record hRecord, const struct ANSegment_ * pValue, NInt * pIndex);
NResult N_API ANType20RecordInsertSegment(HANType20Record hRecord, NInt index, const struct ANSegment_ * pValue);
NResult N_API ANType20RecordRemoveSegmentAt(HANType20Record hRecord, NInt index);
NResult N_API ANType20RecordClearSegments(HANType20Record hRecord);

NResult N_API ANType20RecordGetSegmentVertexCount(HANType20Record hRecord, NInt segmentIndex, NInt * pValue);
NResult N_API ANType20RecordGetSegmentVertex(HANType20Record hRecord, NInt segmentIndex, NInt index, struct NPoint_ * pValue);
NResult N_API ANType20RecordGetSegmentVertices(HANType20Record hRecord, NInt segmentIndex, struct NPoint_ * * parValues, NInt * pValueCount);
NResult N_API ANType20RecordSetSegmentVertex(HANType20Record hRecord, NInt segmentIndex, NInt index, const struct NPoint_ * pValue);
NResult N_API ANType20RecordAddSegmentVertex(HANType20Record hRecord, NInt segmentIndex, const struct NPoint_ * pValue, NInt * pIndex);
NResult N_API ANType20RecordInsertSegmentVertex(HANType20Record hRecord, NInt segmentIndex, NInt index, const struct NPoint_ * pValue);
NResult N_API ANType20RecordRemoveSegmentVertexAt(HANType20Record hRecord, NInt segmentIndex, NInt index);
NResult N_API ANType20RecordClearSegmentVertices(HANType20Record hRecord, NInt segmentIndex);

NResult N_API ANType20RecordGetTimeIndexCount(HANType20Record hRecord, NInt * pValue);
NResult N_API ANType20RecordGetTimeIndex(HANType20Record hRecord, NInt index, struct ANTimeIndex_ * pValue);
NResult N_API ANType20RecordGetTimeIndexCapacity(HANType20Record hRecord, NInt * pValue);
NResult N_API ANType20RecordSetTimeIndexCapacity(HANType20Record hRecord, NInt value);
NResult N_API ANType20RecordGetTimeIndexes(HANType20Record hRecord, struct ANTimeIndex_ * * parValues, NInt * pValueCount);
NResult N_API ANType20RecordSetTimeIndex(HANType20Record hRecord, NInt index, const struct ANTimeIndex_ * pValue);
NResult N_API ANType20RecordAddTimeIndex(HANType20Record hRecord, const struct ANTimeIndex_ * pValue, NInt * pIndex);
NResult N_API ANType20RecordInsertTimeIndex(HANType20Record hRecord, NInt index, const struct ANTimeIndex_ * pValue);
NResult N_API ANType20RecordRemoveTimeIndexAt(HANType20Record hRecord, NInt index);
NResult N_API ANType20RecordClearTimeIndexes(HANType20Record hRecord);

NResult N_API ANType20RecordGetRepresentationNumber(HANType20Record hRecord, NUInt * pValue);
NResult N_API ANType20RecordSetRepresentationNumber(HANType20Record hRecord, NUInt value);

NResult N_API ANType20RecordGetCaptureDateRangeN(HANType20Record hRecord, HNString * phValue);
NResult N_API ANType20RecordSetCaptureDateRangeN(HANType20Record hRecord, HNString hValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API ANType20RecordSetCaptureDateRangeA(HANType20Record hRecord, const NAChar * szValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API ANType20RecordSetCaptureDateRangeW(HANType20Record hRecord, const NWChar * szValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API ANType20RecordSetCaptureDateRange(HANType20Record hRecord, const NChar * szValue);
#endif
#define ANType20RecordSetCaptureDateRange N_FUNC_AW(ANType21RecordSetCaptureDateRange)

#ifdef N_CPP
}
#endif

#endif // !AN_TYPE_20_RECORD_H_INCLUDED
