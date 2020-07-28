#ifndef AN_TYPE_99_RECORD_HPP_INCLUDED
#define AN_TYPE_99_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANAsciiBinaryRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANType99Record.h>
}}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANBiometricType)

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_TYPE_99_RECORD_FIELD_LEN
#undef AN_TYPE_99_RECORD_FIELD_IDC
#undef AN_TYPE_99_RECORD_FIELD_SRC
#undef AN_TYPE_99_RECORD_FIELD_BCD

#undef AN_TYPE_99_RECORD_FIELD_HDV
#undef AN_TYPE_99_RECORD_FIELD_BTY
#undef AN_TYPE_99_RECORD_FIELD_BDQ
#undef AN_TYPE_99_RECORD_FIELD_BFO
#undef AN_TYPE_99_RECORD_FIELD_BFT

#undef AN_TYPE_99_RECORD_FIELD_ANN
#undef AN_TYPE_99_RECORD_FIELD_DUI
#undef AN_TYPE_99_RECORD_FIELD_MMS

#undef AN_TYPE_99_RECORD_FIELD_SAN
#undef AN_TYPE_99_RECORD_FIELD_ASC
#undef AN_TYPE_99_RECORD_FIELD_HAS
#undef AN_TYPE_99_RECORD_FIELD_SOR
#undef AN_TYPE_99_RECORD_FIELD_GEO

#undef AN_TYPE_99_RECORD_FIELD_UDF_FROM
#undef AN_TYPE_99_RECORD_FIELD_UDF_TO
#undef AN_TYPE_99_RECORD_FIELD_UDF_TO_V5

#undef AN_TYPE_99_RECORD_FIELD_BDB

#undef AN_TYPE_99_RECORD_HEADER_VERSION_1_0
#undef AN_TYPE_99_RECORD_HEADER_VERSION_1_1

#undef AN_TYPE_99_RECORD_MAX_BIOMETRIC_DATA_QUALITY_COUNT
#undef AN_TYPE_99_RECORD_MAX_BIOMETRIC_DATA_QUALITY_COUNT_V5

const NInt AN_TYPE_99_RECORD_FIELD_LEN = AN_RECORD_FIELD_LEN;
const NInt AN_TYPE_99_RECORD_FIELD_IDC = AN_RECORD_FIELD_IDC;
const NInt AN_TYPE_99_RECORD_FIELD_SRC = AN_ASCII_BINARY_RECORD_FIELD_SRC;
const NInt AN_TYPE_99_RECORD_FIELD_BCD = AN_ASCII_BINARY_RECORD_FIELD_DAT;

const NInt AN_TYPE_99_RECORD_FIELD_HDV = 100;
const NInt AN_TYPE_99_RECORD_FIELD_BTY = 101;
const NInt AN_TYPE_99_RECORD_FIELD_BDQ = 102;
const NInt AN_TYPE_99_RECORD_FIELD_BFO = 103;
const NInt AN_TYPE_99_RECORD_FIELD_BFT = 104;

const NInt AN_TYPE_99_RECORD_FIELD_ANN = AN_ASCII_BINARY_RECORD_FIELD_ANN;
const NInt AN_TYPE_99_RECORD_FIELD_DUI = AN_ASCII_BINARY_RECORD_FIELD_DUI;
const NInt AN_TYPE_99_RECORD_FIELD_MMS = AN_ASCII_BINARY_RECORD_FIELD_MMS;

const NInt AN_TYPE_99_RECORD_FIELD_SAN = AN_ASCII_BINARY_RECORD_FIELD_SAN;
const NInt AN_TYPE_99_RECORD_FIELD_ASC = AN_ASCII_BINARY_RECORD_FIELD_ASC;
const NInt AN_TYPE_99_RECORD_FIELD_HAS = AN_ASCII_BINARY_RECORD_FIELD_HAS;
const NInt AN_TYPE_99_RECORD_FIELD_SOR = AN_ASCII_BINARY_RECORD_FIELD_SOR;
const NInt AN_TYPE_99_RECORD_FIELD_GEO = AN_ASCII_BINARY_RECORD_FIELD_GEO;

const NInt AN_TYPE_99_RECORD_FIELD_UDF_FROM = AN_ASCII_BINARY_RECORD_FIELD_UDF_FROM;
const NInt AN_TYPE_99_RECORD_FIELD_UDF_TO = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO;
const NInt AN_TYPE_99_RECORD_FIELD_UDF_TO_V5 = AN_ASCII_BINARY_RECORD_FIELD_UDF_TO_V5;

const NInt AN_TYPE_99_RECORD_FIELD_BDB = AN_RECORD_FIELD_DATA;

const NVersion AN_TYPE_99_RECORD_HEADER_VERSION_1_0(0x0100);
const NVersion AN_TYPE_99_RECORD_HEADER_VERSION_1_1(0x0101);

const NByte AN_TYPE_99_RECORD_MAX_BIOMETRIC_DATA_QUALITY_COUNT = 1;
const NByte AN_TYPE_99_RECORD_MAX_BIOMETRIC_DATA_QUALITY_COUNT_V5 = 9;

#include <Core/NNoDeprecate.h>
class ANType99Record : public ANAsciiBinaryRecord
{
	N_DECLARE_OBJECT_CLASS(ANType99Record, ANAsciiBinaryRecord)

public:
	class BiometricDataQualityCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase<ANQualityMetric, ANType99Record,
		ANType99RecordGetBiometricDataQualityCount, ANType99RecordGetBiometricDataQualityEx, ANType99RecordGetBiometricDataQualities>
	{
		BiometricDataQualityCollection(const ANType99Record & owner)
		{
			SetOwner(owner);
		}

		friend class ANType99Record;
	public:
		using ::Neurotec::Collections::NCollectionWithAllOutBase<ANQualityMetric, ANType99Record,
			ANType99RecordGetBiometricDataQualityCount, ANType99RecordGetBiometricDataQualityEx, ANType99RecordGetBiometricDataQualities>::GetAll;

		void Set(NInt index, const ANQualityMetric & value)
		{
			NCheck(ANType99RecordSetBiometricDataQualityEx(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ANQualityMetric & value)
		{
			NInt index;
			NCheck(ANType99RecordAddBiometricDataQuality(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ANQualityMetric & value)
		{
			NCheck(ANType99RecordInsertBiometricDataQuality(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANType99RecordRemoveBiometricDataQualityAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANType99RecordClearBiometricDataQualities(this->GetOwnerHandle()));
		}
	};

private:
	static HANType99Record Create(NVersion version, NInt idc, NUInt flags)
	{
		HANType99Record handle;
		NCheck(ANType99RecordCreate(version.GetValue(), idc, flags, &handle));
		return handle;
	}

	static HANType99Record Create(NUInt flags)
	{
		HANType99Record handle;
		NCheck(ANType99RecordCreateEx(flags, &handle));
		return handle;
	}

public:
	static NType ANBiometricTypeNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANBiometricType), true);
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType99() instead")
	explicit ANType99Record(NVersion version, NInt idc, NUInt flags = 0)
		: ANAsciiBinaryRecord(Create(version, idc, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and AddType99() instead")
	explicit ANType99Record(NUInt flags = 0)
		: ANAsciiBinaryRecord(Create(flags), true)
	{
	}

	NVersion GetHeaderVersion() const
	{
		NVersion_ value;
		NCheck(ANType99RecordGetHeaderVersion(GetHandle(), &value));
		return NVersion(value);
	}

	void SetHeaderVersion(NVersion value)
	{
		NCheck(ANType99RecordSetHeaderVersion(GetHandle(), value.GetValue()));
	}

	ANBiometricType GetBiometricType() const
	{
		ANBiometricType value;
		NCheck(ANType99RecordGetBiometricType(GetHandle(), &value));
		return value;
	}

	void SetBiometricType(ANBiometricType value)
	{
		NCheck(ANType99RecordSetBiometricType(GetHandle(), value));
	}

	NUShort GetBdbFormatOwner() const
	{
		NUShort value;
		NCheck(ANType99RecordGetBdbFormatOwner(GetHandle(), &value));
		return value;
	}

	void SetBdbFormatOwner(NUShort value)
	{
		NCheck(ANType99RecordSetBdbFormatOwner(GetHandle(), value));
	}

	NUShort GetBdbFormatType() const
	{
		NUShort value;
		NCheck(ANType99RecordGetBdbFormatType(GetHandle(), &value));
		return value;
	}

	void SetBdbFormatType(NUShort value)
	{
		NCheck(ANType99RecordSetBdbFormatType(GetHandle(), value));
	}

	BiometricDataQualityCollection GetBiometricDataQualities()
	{
		return BiometricDataQualityCollection(*this);
	}

	const BiometricDataQualityCollection GetBiometricDataQualities() const
	{
		return BiometricDataQualityCollection(*this);
	}
};
#include <Core/NReDeprecate.h>

}}}

#endif // !AN_TYPE_99_RECORD_HPP_INCLUDED
