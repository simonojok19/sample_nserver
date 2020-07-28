#ifndef AN_IMAGE_BINARY_RECORD_HPP_INCLUDED
#define AN_IMAGE_BINARY_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANBinaryRecord.hpp>
#include <Biometrics/Standards/ANImage.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANImageBinaryRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_IMAGE_BINARY_RECORD_FIELD_ISR
#undef AN_IMAGE_BINARY_RECORD_FIELD_HLL
#undef AN_IMAGE_BINARY_RECORD_FIELD_VLL

#undef AN_IMAGE_BINARY_RECORD_MIN_LINE_LENGTH_V5
#undef AN_IMAGE_BINARY_RECORD_MAX_LINE_LENGTH_V5

const NInt AN_IMAGE_BINARY_RECORD_FIELD_ISR = 5;
const NInt AN_IMAGE_BINARY_RECORD_FIELD_HLL = 6;
const NInt AN_IMAGE_BINARY_RECORD_FIELD_VLL = 7;

const NInt AN_IMAGE_BINARY_RECORD_MIN_LINE_LENGTH_V5 = 10;
const NInt AN_IMAGE_BINARY_RECORD_MAX_LINE_LENGTH_V5 = 65535;

class ANImageBinaryRecord : public ANBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANImageBinaryRecord, ANBinaryRecord)

public:
	::Neurotec::Images::NImage ToNImage(NUInt flags = 0) const
	{
		HNImage hImage;
		NCheck(ANImageBinaryRecordToNImage(GetHandle(), flags, &hImage));
		return FromHandle< ::Neurotec::Images::NImage>(hImage);
	}

	bool GetImageScanResolution() const
	{
		NBool value;
		NCheck(ANImageBinaryRecordGetImageScanResolution(GetHandle(), &value));
		return value != 0;
	}

	void SetImageScanResolution(bool value)
	{
		NCheck(ANImageBinaryRecordSetImageScanResolution(GetHandle(), value != 0));
	}

	NUInt GetImageScanResolutionValue() const
	{
		NUInt value;
		NCheck(ANImageBinaryRecordGetImageScanResolutionValue(GetHandle(), &value));
		return value;
	}

	NUInt GetImageResolution() const
	{
		NUInt value;
		NCheck(ANImageBinaryRecordGetImageResolution(GetHandle(), &value));
		return value;
	}

	NUShort GetHorzLineLength() const
	{
		NUShort value;
		NCheck(ANImageBinaryRecordGetHorzLineLength(GetHandle(), &value));
		return value;
	}

	void SetHorzLineLength(NUShort value)
	{
		NCheck(ANImageBinaryRecordSetHorzLineLength(GetHandle(), value));
	}

	NUShort GetVertLineLength() const
	{
		NUShort value;
		NCheck(ANImageBinaryRecordGetVertLineLength(GetHandle(), &value));
		return value;
	}

	void SetVertLineLength(NUShort value)
	{
		NCheck(ANImageBinaryRecordSetVertLineLength(GetHandle(), value));
	}

	void SetImage(::Neurotec::Images::NImage image, NUInt flags = 0) const
	{
		NCheck(ANImageBinaryRecordSetImage(GetHandle(), image.GetHandle(), flags));
	}
};

}}}

#endif // !AN_IMAGE_BINARY_RECORD_HPP_INCLUDED
