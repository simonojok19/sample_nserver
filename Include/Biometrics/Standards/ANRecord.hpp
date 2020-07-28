#include <Biometrics/Standards/BdifTypes.hpp>
#include <Biometrics/Standards/ANField.hpp>
#include <Core/NDateTime.hpp>

#ifndef AN_RECORD_HPP_INCLUDED
#define AN_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANRecordType.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANRecord.h>
}}}

#include <Core/NNoDeprecate.h>
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANValidationLevel)
#include <Core/NReDeprecate.h>

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_RECORD_MAX_FIELD_NUMBER

#undef AN_RECORD_FIELD_LEN
#undef AN_RECORD_FIELD_IDC

#undef AN_RECORD_FIELD_DATA

#undef AN_RECORD_MAX_IDC
#undef AN_RECORD_MAX_IDC_V5

#undef AN_RECORD_MIN_DEVICE_UNIQUE_IDENTIFIER_LENGTH
#undef AN_RECORD_MAX_DEVICE_UNIQUE_IDENTIFIER_LENGTH

#undef ANR_MERGE_DUPLICATE_FIELDS
#undef ANR_RECOVER_FROM_BINARY_DATA

#undef AN_RECORD_MAX_MAKE_LENGTH
#undef AN_RECORD_MAX_MODEL_LENGTH
#undef AN_RECORD_MAX_SERIAL_NUMBER_LENGTH

#undef AN_RECORD_ANN_MIN_PROCESSING_ALGORITHM_NAME_LENGTH
#undef AN_RECORD_ANN_MAX_PROCESSING_ALGORITHM_NAME_LENGTH_V50
#undef AN_RECORD_ANN_MIN_PROCESSING_ALGORITHM_OWNER_LENGTH
#undef AN_RECORD_ANN_MAX_PROCESSING_ALGORITHM_OWNER_LENGTH
#undef AN_RECORD_ANN_MIN_PROCESS_DESCRIPTION_LENGTH
#undef AN_RECORD_ANN_MAX_PROCESS_DESCRIPTION_LENGTH_V50

#undef AN_RECORD_ANN_UNKNOWN_PROCESSING_ALGORITHM_OWNER

const NInt AN_RECORD_MAX_FIELD_NUMBER = 999;

const NInt AN_RECORD_FIELD_LEN = 1;
const NInt AN_RECORD_FIELD_IDC = 2;

const NInt AN_RECORD_FIELD_DATA = 999;

const NInt AN_RECORD_MAX_IDC = 255;
const NInt AN_RECORD_MAX_IDC_V5 = 99;

const NByte AN_RECORD_MIN_DEVICE_UNIQUE_IDENTIFIER_LENGTH = 13;
const NByte AN_RECORD_MAX_DEVICE_UNIQUE_IDENTIFIER_LENGTH = 16;

const NUInt ANR_MERGE_DUPLICATE_FIELDS = 0x00000100;
const NUInt ANR_RECOVER_FROM_BINARY_DATA = 0x00000200;

const NInt AN_RECORD_MAX_MAKE_LENGTH = 50;
const NInt AN_RECORD_MAX_MODEL_LENGTH = 50;
const NInt AN_RECORD_MAX_SERIAL_NUMBER_LENGTH = 50;

const NUInt AN_RECORD_ANN_MIN_PROCESSING_ALGORITHM_NAME_LENGTH = 1;
const NUInt AN_RECORD_ANN_MAX_PROCESSING_ALGORITHM_NAME_LENGTH_V50 = 64;
const NUInt AN_RECORD_ANN_MIN_PROCESSING_ALGORITHM_OWNER_LENGTH = 1;
const NUInt AN_RECORD_ANN_MAX_PROCESSING_ALGORITHM_OWNER_LENGTH = 64;
const NUInt AN_RECORD_ANN_MIN_PROCESS_DESCRIPTION_LENGTH = 1;
const NUInt AN_RECORD_ANN_MAX_PROCESS_DESCRIPTION_LENGTH_V50 = 255;

const NChar AN_RECORD_ANN_UNKNOWN_PROCESSING_ALGORITHM_OWNER[] = N_T("N/A");

class ANAnnotation : public ANAnnotation_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(ANAnnotation)

public:
	ANAnnotation(const NDateTime & Gmt, const NStringWrapper & processingAlgorithm, const NStringWrapper & algorithmOwner, const NStringWrapper & processDescription)
	{
		NCheck(ANAnnotationCreateN(Gmt.GetValue(), processingAlgorithm.GetHandle(), algorithmOwner.GetHandle(), processDescription.GetHandle(), this));
	}

	NDateTime GetGmt() const
	{
		return NDateTime(gmt);
	}

	void SetGmt(const NDateTime & value)
	{
		
		gmt = value.GetValue();
	}

	NString GetProcessingAlgorithmName() const
	{
		return NString(hProcessingAlgorithmName, false);
	}

	void SetProcessingAlgorithmName(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hProcessingAlgorithmName));
	}

	NString GetAlgorithmOwner() const
	{
		return NString(hAlgorithmOwner, false);
	}

	void SetAlgorithmOwner(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hAlgorithmOwner));
	}

	NString GetProcessDescription() const
	{
		return NString(hProcessDescription, false);
	}

	void SetProcessDescription(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hProcessDescription));
	}
};

class ANMakeModelSerialNumber : public ANMakeModelSerialNumber_
{
	N_DECLARE_EQUATABLE_DISPOSABLE_STRUCT_CLASS(ANMakeModelSerialNumber)

public:
	ANMakeModelSerialNumber(const NStringWrapper & make, const NStringWrapper & model, const NStringWrapper & serialNumber)
	{
		NCheck(ANMakeModelSerialNumberCreateN(make.GetHandle(), model.GetHandle(), serialNumber.GetHandle(), this));
	}

	NString GetMake() const
	{
		return NString(hMake, false);
	}

	void SetMake(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hMake));
	}

	NString GetModel() const
	{
		return NString(hModel, false);
	}

	void SetModel(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hModel));
	}

	NString GetSerialNumber() const
	{
		return NString(hSerialNumber, false);
	}

	void SetSerialNumber(const NStringWrapper & value)
	{
		NCheck(NStringSet(value.GetHandle(), &hSerialNumber));
	}
};

}}}

N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANAnnotation)
N_DEFINE_DISPOSABLE_STRUCT_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANMakeModelSerialNumber)

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANTemplate;

#include <Core/NNoDeprecate.h>
class ANRecord : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANRecord, NObject)

public:
	class FieldCollection : public ::Neurotec::Collections::NCollectionBase<ANField, ANRecord,
		ANRecordGetFieldCount, ANRecordGetFieldEx>
	{
		FieldCollection(const ANRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANRecord;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANRecordGetFieldCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANRecordSetFieldCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANRecordRemoveFieldAt(this->GetOwnerHandle(), index));
		}

		ANField Add(NInt fieldNumber, const NStringWrapper & value, NInt * pIndex = NULL)
		{
			HANField hValue;
			NCheck(ANRecordAddFieldN(this->GetOwnerHandle(), fieldNumber, value.GetHandle(), pIndex, &hValue));
			return FromHandle<ANField>(hValue, true);
		}

		ANField Add(NInt fieldNumber, const NStringWrapper & name, const NStringWrapper & value, NInt * pIndex = NULL)
		{
			HANField hValue;
			NCheck(ANRecordAddFieldExN(this->GetOwnerHandle(), fieldNumber, name.GetHandle(), value.GetHandle(), pIndex, &hValue));
			return FromHandle<ANField>(hValue, true);
		}

		ANField Insert(NInt index, NInt fieldNumber, const NStringWrapper & value)
		{
			HANField hValue;
			NCheck(ANRecordInsertFieldN(this->GetOwnerHandle(), index, fieldNumber, value.GetHandle(), &hValue));
			return FromHandle<ANField>(hValue, true);
		}

		ANField Insert(NInt index, NInt fieldNumber, const NStringWrapper & name, const NStringWrapper & value)
		{
			HANField hValue;
			NCheck(ANRecordInsertFieldExN(this->GetOwnerHandle(), index, fieldNumber, name.GetHandle(), value.GetHandle(), &hValue));
			return FromHandle<ANField>(hValue, true);
		}

		NInt IndexOf(NInt fieldNumber) const
		{
			NInt index;
			NCheck(ANRecordGetFieldIndexByNumber(this->GetOwnerHandle(), fieldNumber, &index));
			return index;
		}

		bool Contains(NInt fieldNumber) const
		{
			return IndexOf(fieldNumber) != -1;
		}

		ANField GetByNumber(NInt fieldNumber) const
		{
			HANField hField;
			NCheck(ANRecordGetFieldByNumberEx(this->GetOwnerHandle(), fieldNumber, &hField));
			return FromHandle<ANField>(hField, true);
		}
	};

	class ConformanceTestResultCollection : public ::Neurotec::Collections::NCollectionBase<BdifConformanceTest, ANRecord,
		ANRecordGetConformanceTestResultCount, ANRecordGetConformanceTestResult>
	{
		ConformanceTestResultCollection(const ANRecord & owner)
		{
			SetOwner(owner);
		}

		friend class ANRecord;
	};
private:
	static HANRecord Create(const ANRecordType & recordType, NVersion version, NInt idc, NUInt flags)
	{
		HANRecord handle;
		NCheck(ANRecordCreate(recordType.GetHandle(), version.GetValue(), idc, flags, &handle));
		return handle;
	}

	static HANRecord Create(const ANRecordType & recordType, NUInt flags)
	{
		HANRecord handle;
		NCheck(ANRecordCreateEx(recordType.GetHandle(), flags, &handle));
		return handle;
	}

public:
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and Add(const ANRecordType) instead")
	explicit ANRecord(const ANRecordType & recordType, NVersion version, NInt idc, NUInt flags = 0)
		: NObject(Create(recordType, version, idc, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and Add(const ANRecordType) instead")
	ANRecord(const ANRecordType & recordType, NUInt flags = 0)
		: NObject(Create(recordType, flags), true)
	{
	}

	void BeginUpdate()
	{
		NCheck(ANRecordBeginUpdate(GetHandle()));
	}

	void EndUpdate()
	{
		NCheck(ANRecordEndUpdate(GetHandle()));
	}

	ANRecordType GetRecordType() const
	{
		return GetObject<HandleType, ANRecordType>(ANRecordGetRecordTypeEx, true);
	}

	bool GetIsValidated() const
	{
		NBool value;
		NCheck(ANRecordIsValidated(GetHandle(), &value));
		return value != 0;
	}
	N_DEPRECATED("function is deprecated, ANRecord allow only anvlStandard validation level")
	ANValidationLevel GetValidationLevel() const
	{
		ANValidationLevel value;
		NCheck(ANRecordGetValidationLevel(GetHandle(), &value));
		return value;
	}
	N_DEPRECATED("function is deprecated, use CheckValidity instead")
	void Validate()
	{
		NCheck(ANRecordValidate(GetHandle()));
	}

	bool CheckValidity()
	{
		NBool value;
		NCheck(ANRecordCheckValidity(GetHandle(), &value));
		return value != 0;
	}

	NSizeType GetLength() const
	{
		NSizeType value;
		NCheck(ANRecordGetLength(GetHandle(), &value));
		return value;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(ANRecordGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	NInt GetIdc() const
	{
		NInt value;
		NCheck(ANRecordGetIdc(GetHandle(), &value));
		return value;
	}

	void SetIdc(NInt value)
	{
		NCheck(ANRecordSetIdc(GetHandle(), value));
	}

	::Neurotec::IO::NBuffer GetData() const
	{
		return GetObject<HandleType, ::Neurotec::IO::NBuffer>(ANRecordGetDataN, true);
	}

	void SetData(const ::Neurotec::IO::NBuffer & value)
	{
		SetObject(ANRecordSetDataN, value);
	}

	void SetData(const void * pValue, NSizeType valueSize, bool copy = true)
	{
		NCheck(ANRecordSetDataEx(GetHandle(), pValue, valueSize, copy ? NTrue : NFalse));
	}

	FieldCollection GetFields()
	{
		return FieldCollection(*this);
	}

	const FieldCollection GetFields() const
	{
		return FieldCollection(*this);
	}

	ConformanceTestResultCollection GetConformanceTestResults()
	{
		return ConformanceTestResultCollection(*this);
	}

	const ConformanceTestResultCollection GetConformanceTestResults() const
	{
		return ConformanceTestResultCollection(*this);
	}

	ANTemplate GetOwner() const;
};

}}}

#include <Biometrics/Standards/ANTemplate.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards
{

inline ANTemplate ANRecord::GetOwner() const
{
	return NObject::GetOwner<ANTemplate>();
}
#include <Core/NReDeprecate.h>

}}}

#endif // !AN_RECORD_HPP_INCLUDED
