#ifndef AN_TYPE_5_RECORD_HPP_INCLUDED
#define AN_TYPE_5_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANFImageBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType5Record.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_5_RECORD_FIELD_LEN
#undef AN_TYPE_5_RECORD_FIELD_IDC
#undef AN_TYPE_5_RECORD_FIELD_IMP
#undef AN_TYPE_5_RECORD_FIELD_FGP
#undef AN_TYPE_5_RECORD_FIELD_ISR
#undef AN_TYPE_5_RECORD_FIELD_HLL
#undef AN_TYPE_5_RECORD_FIELD_VLL
#undef AN_TYPE_5_RECORD_FIELD_BCA
#undef AN_TYPE_5_RECORD_FIELD_DATA

const NInt AN_TYPE_5_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_5_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;
const NInt AN_TYPE_5_RECORD_FIELD_IMP = AN_F_IMAGE_BINARY_RECORD_FIELD_IMP;
const NInt AN_TYPE_5_RECORD_FIELD_FGP = AN_F_IMAGE_BINARY_RECORD_FIELD_FGP;
const NInt AN_TYPE_5_RECORD_FIELD_ISR = AN_IMAGE_BINARY_RECORD_FIELD_ISR;
const NInt AN_TYPE_5_RECORD_FIELD_HLL = AN_IMAGE_BINARY_RECORD_FIELD_HLL;
const NInt AN_TYPE_5_RECORD_FIELD_VLL = AN_IMAGE_BINARY_RECORD_FIELD_VLL;
const NInt AN_TYPE_5_RECORD_FIELD_BCA = AN_F_IMAGE_BINARY_RECORD_FIELD_CA;
const NInt AN_TYPE_5_RECORD_FIELD_DATA = AN_RECORD_FIELD_DATA;

#include <Core/NNoDeprecate.h>
class ANType5Record : public ANFImageBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType5Record, ANFImageBinaryRecord)

private:
	static HANType5Record Create(NVersion version, NInt idc, NUInt flags)
	{
		HANType5Record handle;
		NCheck(ANType5RecordCreate(version.GetValue(), idc, flags, &handle));
		return handle;
	}

	static HANType5Record Create(NVersion version, NInt idc, bool isr, ANBinaryImageCompressionAlgorithm bca, const ::Neurotec::Images::NImage & image, NUInt flags)
	{
		HANType5Record handle;
		NCheck(ANType5RecordCreateFromNImage(version.GetValue(), idc, isr, bca, image.GetHandle(), flags, &handle));
		return handle;
	}

public:
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType5() instead")
	explicit ANType5Record(NVersion version, NInt idc, NUInt flags = 0)
		: ANFImageBinaryRecord(Create(version, idc, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType5(bool, ANBinaryImageCompressionAlgorithm, const ::Neurotec::Images::NImage) instead")
	ANType5Record(NVersion version, NInt idc, bool isr, ANBinaryImageCompressionAlgorithm bca, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		: ANFImageBinaryRecord(Create(version, idc, isr, bca, image, flags), true)
	{
	}

	ANBinaryImageCompressionAlgorithm GetCompressionAlgorithm() const
	{
		ANBinaryImageCompressionAlgorithm value;
		NCheck(ANType5RecordGetCompressionAlgorithm(GetHandle(), &value));
		return value;
	}

	NByte GetVendorCompressionAlgorithm() const
	{
		NByte value;
		NCheck(ANType5RecordGetVendorCompressionAlgorithm(GetHandle(), &value));
		return value;
	}

	void SetCompressionAlgorithm(ANBinaryImageCompressionAlgorithm value, NByte vendorValue)
	{
		NCheck(ANType5RecordSetCompressionAlgorithm(GetHandle(), value, vendorValue));
	}
};
#include <Core/NReDeprecate.h>

}}}

#endif // !AN_TYPE_5_RECORD_HPP_INCLUDED
