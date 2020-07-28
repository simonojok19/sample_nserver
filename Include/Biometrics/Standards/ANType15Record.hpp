#ifndef AN_TYPE_15_RECORD_HPP_INCLUDED
#define AN_TYPE_15_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType15Record.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_15_RECORD_FIELD_LEN
#undef AN_TYPE_15_RECORD_FIELD_IDC
#undef AN_TYPE_15_RECORD_FIELD_IMP
#undef AN_TYPE_15_RECORD_FIELD_SRC
#undef AN_TYPE_15_RECORD_FIELD_PCD
#undef AN_TYPE_15_RECORD_FIELD_HLL
#undef AN_TYPE_15_RECORD_FIELD_VLL
#undef AN_TYPE_15_RECORD_FIELD_SLC
#undef AN_TYPE_15_RECORD_FIELD_HPS
#undef AN_TYPE_15_RECORD_FIELD_VPS
#undef AN_TYPE_15_RECORD_FIELD_CGA
#undef AN_TYPE_15_RECORD_FIELD_BPX
#undef AN_TYPE_15_RECORD_FIELD_PLP
#undef AN_TYPE_15_RECORD_FIELD_SHPS
#undef AN_TYPE_15_RECORD_FIELD_SVPS
#undef AN_TYPE_15_RECORD_FIELD_AMP
#undef AN_TYPE_15_RECORD_FIELD_COM
#undef AN_TYPE_15_RECORD_FIELD_SEG
#undef AN_TYPE_15_RECORD_FIELD_PQM
#undef AN_TYPE_15_RECORD_FIELD_DMM
#undef AN_TYPE_15_RECORD_FIELD_PAP

#undef AN_TYPE_15_RECORD_FIELD_SUB
#undef AN_TYPE_15_RECORD_FIELD_CON

#undef AN_TYPE_15_RECORD_FIELD_FCT
#undef AN_TYPE_15_RECORD_FIELD_ANN
#undef AN_TYPE_15_RECORD_FIELD_DUI
#undef AN_TYPE_15_RECORD_FIELD_MMS

#undef AN_TYPE_15_RECORD_FIELD_SAN
#undef AN_TYPE_15_RECORD_FIELD_ASC
#undef AN_TYPE_15_RECORD_FIELD_EFR
#undef AN_TYPE_15_RECORD_FIELD_HAS
#undef AN_TYPE_15_RECORD_FIELD_SOR
#undef AN_TYPE_15_RECORD_FIELD_GEO

#undef AN_TYPE_15_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_15_RECORD_FIELD_UDF_TO
#undef AN_TYPE_15_RECORD_FIELD_UDF_TO_V5

#undef AN_TYPE_15_RECORD_FIELD_DATA

#undef AN_TYPE_15_RECORD_MAX_QUALITY_METRIC_COUNT
#undef AN_TYPE_15_RECORD_MAX_QUALITY_METRIC_COUNT_V5
#undef AN_TYPE_15_RECORD_MAX_AMPUTATION_COUNT
#undef AN_TYPE_15_RECORD_MAX_SEGMENT_COUNT

#undef AN_TYPE_15_RECORD_PAP_70
#undef AN_TYPE_15_RECORD_PAP_80
#undef AN_TYPE_15_RECORD_PAP_170
#undef AN_TYPE_15_RECORD_PAP_180

const NInt AN_TYPE_15_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_15_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;
const NInt AN_TYPE_15_RECORD_FIELD_IMP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_IMP;
const NInt AN_TYPE_15_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_15_RECORD_FIELD_PCD = AN_ASCII_BINARY_RECORD_FIELD_DAT;
const NInt AN_TYPE_15_RECORD_FIELD_HLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HLL;
const NInt AN_TYPE_15_RECORD_FIELD_VLL = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VLL;
const NInt AN_TYPE_15_RECORD_FIELD_SLC = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SLC;
const NInt AN_TYPE_15_RECORD_FIELD_HPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_HPS;
const NInt AN_TYPE_15_RECORD_FIELD_VPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_VPS;
const NInt AN_TYPE_15_RECORD_FIELD_CGA = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_CGA;
const NInt AN_TYPE_15_RECORD_FIELD_BPX = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_BPX;
const NInt AN_TYPE_15_RECORD_FIELD_PLP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FGP;
const NInt AN_TYPE_15_RECORD_FIELD_SHPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SHPS;
const NInt AN_TYPE_15_RECORD_FIELD_SVPS = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_SVPS;
const NInt AN_TYPE_15_RECORD_FIELD_AMP = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_AMP;
const NInt AN_TYPE_15_RECORD_FIELD_COM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_COM;
const NInt AN_TYPE_15_RECORD_FIELD_SEG = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_SEG;
const NInt AN_TYPE_15_RECORD_FIELD_PQM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_IQM;
const NInt AN_TYPE_15_RECORD_FIELD_DMM = AN_IMAGE_ASCII_BINARY_RECORD_FIELD_DMM;

const NInt AN_TYPE_15_RECORD_FIELD_PAP = 31;

const NInt AN_TYPE_15_RECORD_FIELD_SUB = AN_ASCII_BINARY_RECORD_FIELD_SUB;
const NInt AN_TYPE_15_RECORD_FIELD_CON = AN_ASCII_BINARY_RECORD_FIELD_CON;

const NInt AN_TYPE_15_RECORD_FIELD_FCT = AN_FP_IMAGE_ASCII_BINARY_RECORD_FIELD_FCT;
const NInt AN_TYPE_15_RECORD_FIELD_ANN = AN_ASCII_BINARY_RECORD_FIELD_ANN;
const NInt AN_TYPE_15_RECORD_FIELD_DUI = AN_ASCII_BINARY_RECORD_FIELD_DUI;
const NInt AN_TYPE_15_RECORD_FIELD_MMS = AN_ASCII_BINARY_RECORD_FIELD_MMS;

const NInt AN_TYPE_15_RECORD_FIELD_SAN = AN_ASCII_BINARY_RECORD_FIELD_SAN;
const NInt AN_TYPE_15_RECORD_FIELD_ASC = AN_ASCII_BINARY_RECORD_FIELD_ASC;
const NInt AN_TYPE_15_RECORD_FIELD_EFR = AN_ASCII_BINARY_RECORD_FIELD_EFR;
const NInt AN_TYPE_15_RECORD_FIELD_HAS = AN_ASCII_BINARY_RECORD_FIELD_HAS;
const NInt AN_TYPE_15_RECORD_FIELD_SOR = AN_ASCII_BINARY_RECORD_FIELD_SOR;
const NInt AN_TYPE_15_RECORD_FIELD_GEO = AN_ASCII_BINARY_RECORD_FIELD_GEO;

const NInt AN_TYPE_15_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_15_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;
const NInt AN_TYPE_15_RECORD_FIELD_UDF_TO_V5 = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO_V5;

const NInt AN_TYPE_15_RECORD_FIELD_DATA = AN_RECORD_FIELD_DATA;

const NInt AN_TYPE_15_RECORD_MAX_QUALITY_METRIC_COUNT = 4;
const NInt AN_TYPE_15_RECORD_MAX_QUALITY_METRIC_COUNT_V5 = 9;

const NInt AN_TYPE_15_RECORD_MAX_AMPUTATION_COUNT = 9;

const NInt AN_TYPE_15_RECORD_MAX_SEGMENT_COUNT = 17;

const NInt AN_TYPE_15_RECORD_PAP_70 = 70;
const NInt AN_TYPE_15_RECORD_PAP_80 = 80;
const NInt AN_TYPE_15_RECORD_PAP_170 = 170;
const NInt AN_TYPE_15_RECORD_PAP_180 = 180;

#include <Core/NNoDeprecate.h>
class ANType15Record : public ANFPImageAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType15Record, ANFPImageAsciiBinaryRecord)

private:
	static HANType15Record Create(NVersion version, NInt idc, NUInt flags)
	{
		HANType15Record handle;
		NCheck(ANType15RecordCreate(version.GetValue(), idc, flags, &handle));
		return handle;
	}

	static HANType15Record Create(NVersion version, NInt idc, const NStringWrapper & src, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image, NUInt flags)
	{
		HANType15Record handle;
		NCheck(ANType15RecordCreateFromNImageN(version.GetValue(), idc, src.GetHandle(), slc, cga, image.GetHandle(), flags, &handle));
		return handle;
	}

	static HANType15Record Create(NUInt flags)
	{
		HANType15Record handle;
		NCheck(ANType15RecordCreateEx(flags, &handle));
		return handle;
	}

	static HANType15Record Create(const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image, NUInt flags)
	{
		HANType15Record handle;
		NCheck(ANType15RecordCreateFromNImageNEx(src.GetHandle(), slc, cga, image.GetHandle(), flags, &handle));
		return handle;
	}

public:
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType15() instead")
	explicit ANType15Record(NVersion version, NInt idc, NUInt flags = 0)
		: ANFPImageAsciiBinaryRecord(Create(version, idc, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType15(const NStringWrapper, BdifScaleUnits, ANImageCompressionAlgorithm, const NImage) instead")
	ANType15Record(NVersion version, NInt idc, const NStringWrapper & src, BdifScaleUnits slc,
	ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		: ANFPImageAsciiBinaryRecord(Create(version, idc, src, slc, cga, image, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType15() instead")
	explicit ANType15Record(NUInt flags = 0)
		: ANFPImageAsciiBinaryRecord(Create(flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType15(const NStringWrapper, BdifScaleUnits, ANImageCompressionAlgorithm, const NImage) instead")
	ANType15Record(const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		: ANFPImageAsciiBinaryRecord(Create(src, slc, cga, image, flags), true)
	{
	}

	NInt GetSubjectAcquisitionProfile() const
	{
		NInt value;
		NCheck(ANType15RecordGetSubjectAcquisitionProfile(GetHandle(), &value));
		return value;
	}

	void SetSubjectAcquisitionProfile(NInt value)
	{
		NCheck(ANType15RecordSetSubjectAcquisitionProfile(GetHandle(), value));
	}
};
#include <Core/NReDeprecate.h>

}}}

#endif // !AN_TYPE_15_RECORD_HPP_INCLUDED
