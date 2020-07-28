#include <Biometrics/Standards/ANRecord.hpp>

#ifndef AN_TEMPLATE_HPP_INCLUDED
#define AN_TEMPLATE_HPP_INCLUDED

#include <Biometrics/Standards/ANRecordType.hpp>
#include <Biometrics/Standards/ANType1Record.hpp>
#include <Biometrics/Standards/ANType2Record.hpp>
#include <Biometrics/Standards/ANType3Record.hpp>
#include <Biometrics/Standards/ANType4Record.hpp>
#include <Biometrics/Standards/ANType5Record.hpp>
#include <Biometrics/Standards/ANType6Record.hpp>
#include <Biometrics/Standards/ANType7Record.hpp>
#include <Biometrics/Standards/ANType8Record.hpp>
#include <Biometrics/Standards/ANType9Record.hpp>
#include <Biometrics/Standards/ANType10Record.hpp>
#include <Biometrics/Standards/ANType13Record.hpp>
#include <Biometrics/Standards/ANType14Record.hpp>
#include <Biometrics/Standards/ANType15Record.hpp>
#include <Biometrics/Standards/ANType16Record.hpp>
#include <Biometrics/Standards/ANType17Record.hpp>
#include <Biometrics/Standards/ANType20Record.hpp>
#include <Biometrics/Standards/ANType21Record.hpp>
#include <Biometrics/Standards/ANType99Record.hpp>
#include <Images/NImage.hpp>
#include <Biometrics/NTemplate.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
using ::Neurotec::Images::HNImage;
#include <Biometrics/Standards/ANTemplate.h>
}}}
#include <Core/NNoDeprecate.h>
N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::Biometrics::Standards, ANEncodingType)
#include <Core/NReDeprecate.h>

namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Core/NNoDeprecate.h>

#undef AN_TEMPLATE_VERSION_2_0
#undef AN_TEMPLATE_VERSION_2_1
#undef AN_TEMPLATE_VERSION_3_0
#undef AN_TEMPLATE_VERSION_4_0
#undef AN_TEMPLATE_VERSION_5_0
#undef AN_TEMPLATE_VERSION_5_1
#undef AN_TEMPLATE_VERSION_5_2

#undef AN_TEMPLATE_VERSION_CURRENT

#undef ANT_MAX_ANRECORD_COUNT_V5
#undef ANT_MAX_TYPE_8_RECORD_COUNT_V5

#undef ANT_SKIP_NIST_MINUTIA_NEIGHBORS
#undef ANT_LEAVE_INVALID_RECORDS_UNVALIDATED
#undef ANT_USE_TWO_DIGIT_IDC
#undef ANT_USE_TWO_DIGIT_FIELD_NUMBER
#undef ANT_USE_TWO_DIGIT_FIELD_NUMBER_TYPE_1
#undef ANT_ALLOW_OUT_OF_BOUNDS_RESOLUTION
#undef ANT_CONVERT_NOT_SUPPORTED_IMAGES

const NVersion AN_TEMPLATE_VERSION_2_0(0x0200);
const NVersion AN_TEMPLATE_VERSION_2_1(0x0201);
const NVersion AN_TEMPLATE_VERSION_3_0(0x0300);
const NVersion AN_TEMPLATE_VERSION_4_0(0x0400);
const NVersion AN_TEMPLATE_VERSION_5_0(0x0500);
const NVersion AN_TEMPLATE_VERSION_5_1(0x0501);
const NVersion AN_TEMPLATE_VERSION_5_2(0x0502);

const NVersion AN_TEMPLATE_VERSION_CURRENT(AN_TEMPLATE_VERSION_5_2);

const NUInt ANT_MAX_ANRECORD_COUNT_V5 = 1000;
const NUInt ANT_MAX_TYPE_8_RECORD_COUNT_V5 = 2;

const NUInt ANT_LEAVE_INVALID_RECORDS_UNVALIDATED = 0x00020000;
const NUInt ANT_USE_TWO_DIGIT_IDC = 0x00040000;
const NUInt ANT_USE_TWO_DIGIT_FIELD_NUMBER = 0x00080000;
const NUInt ANT_USE_TWO_DIGIT_FIELD_NUMBER_TYPE_1 = 0x00100000;
const NUInt ANT_ALLOW_OUT_OF_BOUNDS_RESOLUTION = 0x00200000;
const NUInt ANT_SKIP_NIST_MINUTIA_NEIGHBORS = 0x00400000;
const NUInt ANT_CONVERT_NOT_SUPPORTED_IMAGES = 0x00800000;

class ANTemplate : public NObject
{
	N_DECLARE_OBJECT_CLASS(ANTemplate, NObject)

public:
	class RecordCollection : public ::Neurotec::Collections::NCollectionBase<ANRecord, ANTemplate,
		ANTemplateGetRecordCount, ANTemplateGetRecordEx>
	{
		RecordCollection(const ANTemplate & owner)
		{
			SetOwner(owner);
		}

		friend class ANTemplate;
	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(ANTemplateGetRecordCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(ANTemplateSetRecordCapacity(this->GetOwnerHandle(), value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(ANTemplateRemoveRecordAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(ANTemplateClearRecords(this->GetOwnerHandle()));
		}
		N_DEPRECATED("function is deprecated, use appropriate ANTemplate constructor and Add(const ANRecordType) instead")
		NInt Add(const ANRecord & value)
		{
			NInt index;
			NCheck(ANTemplateAddRecordEx(this->GetOwnerHandle(), value.GetHandle(), &index));
			return index;
		}
		N_DEPRECATED("function is deprecated, use appropriate AddTypeX instead")
		ANRecord Add(const ANRecordType & recordType)
		{
			HANRecord hRecord;
			NCheck(ANTemplateAddRecord(this->GetOwnerHandle(), recordType.GetHandle(), &hRecord));
			return FromHandle<ANRecord>(hRecord, true);
		}

		ANType2Record AddType2()
		{
			HANType2Record hRecord;
			NCheck(ANTemplateAddType2Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType2Record>(hRecord);
		}

		ANType3Record AddType3()
		{
			HANType3Record hRecord;
			NCheck(ANTemplateAddType3Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType3Record>(hRecord);
		}

		ANType3Record AddType3(bool isr, ANImageCompressionAlgorithm ca, const ::Neurotec::Images::NImage & image)
		{
			HANType3Record hRecord;
			NCheck(ANTemplateAddType3RecordFromNImage(this->GetOwnerHandle(), isr ? NTrue : NFalse, ca, image.GetHandle(), &hRecord));
			return FromHandle<ANType3Record>(hRecord);
		}

		ANType3Record AddType3(bool isr, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType3Record hRecord;
			NCheck(ANTemplateAddType3RecordFromImageDataN(this->GetOwnerHandle(), isr ? NTrue : NFalse, imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType3Record>(hRecord);
		}

		ANType4Record AddType4()
		{
			HANType4Record hRecord;
			NCheck(ANTemplateAddType4Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType4Record>(hRecord);
		}

		ANType4Record AddType4(bool isr, ANImageCompressionAlgorithm ca, const ::Neurotec::Images::NImage & image)
		{
			HANType4Record hRecord;
			NCheck(ANTemplateAddType4RecordFromNImage(this->GetOwnerHandle(), isr ? NTrue : NFalse, ca, image.GetHandle(), &hRecord));
			return FromHandle<ANType4Record>(hRecord);
		}

		ANType4Record AddType4(bool isr, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType4Record hRecord;
			NCheck(ANTemplateAddType4RecordFromImageDataN(this->GetOwnerHandle(), isr ? NTrue : NFalse, imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType4Record>(hRecord);
		}

		ANType5Record AddType5()
		{
			HANType5Record hRecord;
			NCheck(ANTemplateAddType5Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType5Record>(hRecord);
		}

		ANType5Record AddType5(bool isr, ANBinaryImageCompressionAlgorithm bca, const ::Neurotec::Images::NImage & image)
		{
			HANType5Record hRecord;
			NCheck(ANTemplateAddType5RecordFromNImage(this->GetOwnerHandle(), isr ? NTrue : NFalse, bca, image.GetHandle(), &hRecord));
			return FromHandle<ANType5Record>(hRecord);
		}

		ANType6Record AddType6()
		{
			HANType6Record hRecord;
			NCheck(ANTemplateAddType6Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType6Record>(hRecord);
		}

		ANType6Record AddType6(bool isr, ANBinaryImageCompressionAlgorithm bca, const ::Neurotec::Images::NImage & image)
		{
			HANType6Record hRecord;
			NCheck(ANTemplateAddType6RecordFromNImage(this->GetOwnerHandle(), isr ? NTrue : NFalse, bca, image.GetHandle(), &hRecord));
			return FromHandle<ANType6Record>(hRecord);
		}

		ANType7Record AddType7()
		{
			HANType7Record hRecord;
			NCheck(ANTemplateAddType7Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType7Record>(hRecord);
		}

		ANType8Record AddType8()
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType8Record>(hRecord);
		}

		ANType8Record AddType8(ANSignatureType st, ANSignatureRepresentationType srt, bool isr, const ::Neurotec::Images::NImage & image)
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8RecordFromNImage(this->GetOwnerHandle(), st, srt, isr ? NTrue : NFalse, image.GetHandle(), &hRecord));
			return FromHandle<ANType8Record>(hRecord);
		}

		ANType8Record AddType8(ANSignatureType st, const ANPenVector * arPenVectors, NInt penVectorCount)
		{
			HANType8Record hRecord;
			NCheck(ANTemplateAddType8RecordFromVectors(this->GetOwnerHandle(), st, arPenVectors, penVectorCount, &hRecord));
			return FromHandle<ANType8Record>(hRecord);
		}

		ANType9Record AddType9(NUInt flags = 0)
		{
			HANType9Record hRecord;
			NCheck(ANTemplateAddType9Record(this->GetOwnerHandle(), flags, &hRecord));
			return FromHandle<ANType9Record>(hRecord);
		}

		ANType9Record AddType9(const NFRecord & nfRecord, NUInt flags = 0)
		{
			HANType9Record hRecord;
			NCheck(ANTemplateAddType9RecordFromNFRecord(this->GetOwnerHandle(), nfRecord.GetHandle(), flags, &hRecord));
			return FromHandle<ANType9Record>(hRecord);
		}

		ANType9Record AddType9(bool fmtStd, const NFRecord & nfRecord, NUInt flags = 0)
		{
			HANType9Record hRecord;
			NCheck(ANTemplateAddType9RecordFromNFRecordEx(this->GetOwnerHandle(), fmtStd ? NTrue : NFalse, nfRecord.GetHandle(), flags, &hRecord));
			return FromHandle<ANType9Record>(hRecord);
		}

		ANType9Record AddType9(const FMRecord  & fmRecord, NByte fingerViewIndex, NUInt flags = 0)
		{
			HANType9Record hRecord;
			NCheck(ANTemplateAddType9RecordFromFMRecord(this->GetOwnerHandle(), fmRecord.GetHandle(), fingerViewIndex, flags, &hRecord));
			return FromHandle<ANType9Record>(hRecord);
		}

		ANType10Record AddType10(NUInt flags = 0)
		{
			HANType10Record hRecord;
			NCheck(ANTemplateAddType10Record(this->GetOwnerHandle(), flags, &hRecord));
			return FromHandle<ANType10Record>(hRecord);
		}

		ANType10Record AddType10(ANImageType imt, const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image, NUInt flags = 0)
		{
			HANType10Record hRecord;
			NCheck(ANTemplateAddType10RecordFromNImageN(this->GetOwnerHandle(), imt, src.GetHandle(), slc, cga, image.GetHandle(), flags, &hRecord));
			return FromHandle<ANType10Record>(hRecord);
		}

		ANType10Record AddType10(ANImageType imt, const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer, NUInt flags = 0)
		{
			HANType10Record hRecord;
			NCheck(ANTemplateAddType10RecordFromImageDataN(this->GetOwnerHandle(), imt, src.GetHandle(), imageBuffer.GetHandle(), flags, &hRecord));
			return FromHandle<ANType10Record>(hRecord);
		}

		ANType13Record AddType13()
		{
			HANType13Record hRecord;
			NCheck(ANTemplateAddType13Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType13Record>(hRecord);
		}

		ANType13Record AddType13(BdifFPImpressionType imp, const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image)
		{
			HANType13Record hRecord;
			NCheck(ANTemplateAddType13RecordFromNImageN(this->GetOwnerHandle(), imp, src.GetHandle(), slc, cga, image.GetHandle(), &hRecord));
			return FromHandle<ANType13Record>(hRecord);
		}

		ANType13Record AddType13(BdifFPImpressionType imp, const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType13Record hRecord;
			NCheck(ANTemplateAddType13RecordFromImageDataN(this->GetOwnerHandle(), imp, src.GetHandle(), imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType13Record>(hRecord);
		}

		ANType14Record AddType14()
		{
			HANType14Record hRecord;
			NCheck(ANTemplateAddType14Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType14Record>(hRecord);
		}

		ANType14Record AddType14(const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image)
		{
			HANType14Record hRecord;
			NCheck(ANTemplateAddType14RecordFromNImageN(this->GetOwnerHandle(), src.GetHandle(), slc, cga, image.GetHandle(), &hRecord));
			return FromHandle<ANType14Record>(hRecord);
		}

		ANType14Record AddType14(const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType14Record hRecord;
			NCheck(ANTemplateAddType14RecordFromImageDataN(this->GetOwnerHandle(), src.GetHandle(), imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType14Record>(hRecord);
		}

		ANType15Record AddType15()
		{
			HANType15Record hRecord;
			NCheck(ANTemplateAddType15Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType15Record>(hRecord);
		}

		ANType15Record AddType15(const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image)
		{
			HANType15Record hRecord;
			NCheck(ANTemplateAddType15RecordFromNImageN(this->GetOwnerHandle(), src.GetHandle(), slc, cga, image.GetHandle(), &hRecord));
			return FromHandle<ANType15Record>(hRecord);
		}

		ANType15Record AddType15(const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType15Record hRecord;
			NCheck(ANTemplateAddType15RecordFromImageDataN(this->GetOwnerHandle(), src.GetHandle(), imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType15Record>(hRecord);
		}

		ANType16Record AddType16()
		{
			HANType16Record hRecord;
			NCheck(ANTemplateAddType16Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType16Record>(hRecord);
		}

		ANType16Record AddType16(const NStringWrapper & udi, const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image)
		{
			HANType16Record hRecord;
			NCheck(ANTemplateAddType16RecordFromNImageN(this->GetOwnerHandle(), udi.GetHandle(), src.GetHandle(), slc, cga, image.GetHandle(), &hRecord));
			return FromHandle<ANType16Record>(hRecord);
		}

		ANType16Record AddType16(const NStringWrapper & udi, const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType16Record hRecord;
			NCheck(ANTemplateAddType16RecordFromImageDataN(this->GetOwnerHandle(), udi.GetHandle(), src.GetHandle(), imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType16Record>(hRecord);
		}

		ANType17Record AddType17()
		{
			HANType17Record hRecord;
			NCheck(ANTemplateAddType17Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType17Record>(hRecord);
		}

		ANType17Record AddType17(const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image)
		{
			HANType17Record hRecord;
			NCheck(ANTemplateAddType17RecordFromNImageN(this->GetOwnerHandle(), src.GetHandle(), slc, cga, image.GetHandle(), &hRecord));
			return FromHandle<ANType17Record>(hRecord);
		}

		ANType17Record AddType17(const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType17Record hRecord;
			NCheck(ANTemplateAddType17RecordFromImageDataN(this->GetOwnerHandle(), src.GetHandle(), imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType17Record>(hRecord);
		}

		ANType20Record AddType20()
		{
			HANType20Record hRecord;
			NCheck(ANTemplateAddType20Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType20Record>(hRecord);
		}

		ANType20Record AddType20(const NStringWrapper & src, BdifScaleUnits slc, ANImageCompressionAlgorithm cga, const ::Neurotec::Images::NImage & image)
		{
			HANType20Record hRecord;
			NCheck(ANTemplateAddType20RecordFromNImageN(this->GetOwnerHandle(), src.GetHandle(), slc, cga, image.GetHandle(), &hRecord));
			return FromHandle<ANType20Record>(hRecord);
		}

		ANType20Record AddType20(const NStringWrapper & src, const ::Neurotec::IO::NBuffer & imageBuffer)
		{
			HANType20Record hRecord;
			NCheck(ANTemplateAddType20RecordFromImageDataN(this->GetOwnerHandle(), src.GetHandle(), imageBuffer.GetHandle(), &hRecord));
			return FromHandle<ANType20Record>(hRecord);
		}

		ANType21Record AddType21()
		{
			HANType21Record hRecord;
			NCheck(ANTemplateAddType21Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType21Record>(hRecord);
		}

		ANType99Record AddType99()
		{
			HANType99Record hRecord;
			NCheck(ANTemplateAddType99Record(this->GetOwnerHandle(), &hRecord));
			return FromHandle<ANType99Record>(hRecord);
		}
	};

private:
	static HANTemplate Create(NVersion version, ANValidationLevel validationLevel,  NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateEx(version.GetValue(), validationLevel, flags, &handle));
		return handle;
	}

	static HANTemplate Create(NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreate(flags, &handle));
		return handle;
	}

	static HANTemplate Create(NVersion version, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateEx2(version.GetValue(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(NVersion version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateWithTransactionInformationN(version.GetValue(), tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateWithTransactionInformationExN(tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & fileName, ANValidationLevel validationLevel, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromFileN(fileName.GetHandle(), validationLevel, flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & fileName, ANValidationLevel validationLevel, BdifEncodingType encodingType, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromFileExN(fileName.GetHandle(), validationLevel, encodingType, flags, &handle));
		return handle;
	}

	static HANTemplate Create(const NStringWrapper & fileName, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromFileEx2N(fileName.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NBuffer & buffer, ANValidationLevel validationLevel, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryN(buffer.GetHandle(), validationLevel, flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const void * pBuffer, NSizeType bufferSize, ANValidationLevel validationLevel, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryEx(pBuffer, bufferSize, validationLevel, flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NBuffer & buffer, ANValidationLevel validationLevel, BdifEncodingType encodingType, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryExN(buffer.GetHandle(), validationLevel, encodingType, flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const void * pBuffer, NSizeType bufferSize, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryEx2(pBuffer, bufferSize, flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NBuffer & buffer, NUInt flags, NSizeType * pSize)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromMemoryEx2N(buffer.GetHandle(), flags, pSize, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NStream & stream, ANValidationLevel validationLevel, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromStream(stream.GetHandle(), validationLevel, flags, &handle));
		return handle;
	}

	static HANTemplate Create(const ::Neurotec::IO::NStream & stream, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromStreamEx2(stream.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(NVersion version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn,
		bool type9RecordFmtStd, const NTemplate & nTemplate, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromNTemplateExN(version.GetValue(), tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), type9RecordFmtStd ? NTrue : NFalse, nTemplate.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(NVersion version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn,
		const FMRecord & fmRecord, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromFMRecordN(version.GetValue(), tot.GetHandle(), dai.GetHandle(), ori.GetHandle(), tcn.GetHandle(), fmRecord.GetHandle(), flags, &handle));
		return handle;
	}

	static HANTemplate Create(const ANTemplate & srcANTemplate, NVersion version, NUInt flags)
	{
		HANTemplate handle;
		NCheck(ANTemplateCreateFromANTemplate(srcANTemplate.GetHandle(), version.GetValue(), flags, &handle));
		return handle;
	}
public:
	static NType ANValidationLevelNativeTypeOf()
	{
		return NObject::GetObject<NType>(N_TYPE_OF(ANValidationLevel), true);
	}

	static NInt GetVersions(NVersion * arValue, NInt valueLength)
	{
		return NCheck(ANTemplateGetVersionsEx(reinterpret_cast<NVersion_ *>(arValue), valueLength));
	}

	static NArrayWrapper<NVersion> GetVersions()
	{
		NInt count = GetVersions(NULL, 0);
		NArrayWrapper<NVersion> values(count);
		count = GetVersions(values.GetPtr(), count);
		values.SetCount(count);
		return values;
	}

	static bool IsVersionSupported(const NVersion & version)
	{
		NBool value;
		NCheck(ANTemplateIsVersionSupported(version.GetValue(), &value));
		return value != 0;
	}

	static NString GetVersionName(const NVersion & version)
	{
		HNString hValue;
		NCheck(ANTemplateGetVersionNameN(version.GetValue(), &hValue));
		return NString(hValue, true);
	}

	explicit ANTemplate(NVersion version, NUInt flags = 0)
		: NObject(Create(version, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use ANTemplate(NVersion, NUInt) instead")
	explicit ANTemplate(NVersion version, ANValidationLevel validationLevel, NUInt flags = 0)
		: NObject(Create(version, validationLevel, flags), true)
	{
	}

	explicit ANTemplate(NUInt flags = 0)
		: NObject(Create(flags), true)
	{
	}
	
	ANTemplate(NVersion version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn, NUInt flags = 0)
		: NObject(Create(version, tot, dai, ori, tcn, flags), true)
	{
	}

	ANTemplate(const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn, NUInt flags = 0)
		: NObject(Create(tot, dai, ori, tcn, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use ANTemplate(const NStringWrapper, BdifEncodingType, NUInt, bool *) instead")
	ANTemplate(const NStringWrapper & fileName, ANValidationLevel validationLevel, NUInt flags = 0)
		: NObject(Create(fileName, validationLevel, flags), true)
	{
	}
	N_DEPRECATED("function is deprecated, use ANTemplate(const NStringWrapper, BdifEncodingType, NUInt, bool *) instead")
	ANTemplate(const NStringWrapper & fileName, ANValidationLevel validationLevel, BdifEncodingType encodingType, NUInt flags = 0)
		: NObject(Create(fileName, validationLevel, encodingType, flags), true)
	{
	}

	ANTemplate(const NStringWrapper & fileName, NUInt flags = 0)
		: NObject(Create(fileName, flags), true)
	{
	}

	N_DEPRECATED("function is deprecated, use ANTemplate(const ::Neurotec::IO::NBuffer, BdifEncodingType, NUInt, bool *) instead")
	ANTemplate(const ::Neurotec::IO::NBuffer & buffer, ANValidationLevel validationLevel, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, validationLevel, flags, pSize), true)
	{
	}
	N_DEPRECATED("function is deprecated, use ANTemplate(const ::Neurotec::IO::NBuffer, BdifEncodingType, NUInt, bool *, NSizeType *) instead")
	ANTemplate(const ::Neurotec::IO::NBuffer & buffer, ANValidationLevel validationLevel, BdifEncodingType encodingType, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, validationLevel, encodingType, flags, pSize), true)
	{
	}
	N_DEPRECATED("function is deprecated, use ANTemplate(const void *, NSizeType, BdifEncodingType, NUInt, bool *, NSizeType *) instead")
	ANTemplate(const void * pBuffer, NSizeType bufferSize, ANValidationLevel validationLevel, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, validationLevel, flags, pSize), true)
	{
	}

	ANTemplate(const ::Neurotec::IO::NBuffer & buffer, NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(buffer, flags, pSize), true)
	{
	}

	N_DEPRECATED("function is deprecated, use ANTemplate(const ::Neurotec::IO::NStream, BdifEncodingType, NUInt, bool *) instead")
	ANTemplate(const ::Neurotec::IO::NStream & stream, ANValidationLevel validationLevel, NUInt flags = 0)
		: NObject(Create(stream, validationLevel, flags), true)
	{
	}

	ANTemplate(const void * pBuffer, NSizeType bufferSize,  NUInt flags = 0, NSizeType * pSize = NULL)
		: NObject(Create(pBuffer, bufferSize, flags, pSize), true)
	{
	}

	ANTemplate(const ::Neurotec::IO::NStream & stream, NUInt flags = 0)
		: NObject(Create(stream, flags), true)
	{
	}

	ANTemplate(const ANTemplate & srcANTemplate, NVersion version, NUInt flags = 0)
		: NObject(Create(srcANTemplate, version, flags), true)
	{
	}	

	ANTemplate(NVersion version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn,
		bool type9RecordFmtStd, const NTemplate & nTemplate, NUInt flags = 0)
		: NObject(Create(version, tot, dai, ori, tcn, type9RecordFmtStd, nTemplate, flags), true)
	{
	}

	ANTemplate(NVersion version, const NStringWrapper & tot, const NStringWrapper & dai, const NStringWrapper & ori, const NStringWrapper & tcn,
		const FMRecord & fmRecord, NUInt flags = 0)
		: NObject(Create(version, tot, dai, ori, tcn, fmRecord, flags), true)
	{
	}

	void Save(const NStringWrapper & fileName, NUInt flags = 0) const
	{
		NCheck(ANTemplateSaveToFileN(GetHandle(), fileName.GetHandle(), flags));
	}

	void Save(const NStringWrapper & fileName, BdifEncodingType encodingType, NUInt flags = 0) const
	{
		NCheck(ANTemplateSaveToFileExN(GetHandle(), fileName.GetHandle(), encodingType, flags));
	}

	::Neurotec::IO::NBuffer Save(BdifEncodingType encodingType, NUInt flags = 0) const
	{
		HNBuffer hBuffer;
		NCheck(ANTemplateSaveToMemoryN(GetHandle(), encodingType, flags, &hBuffer));
		return FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
	}

	NTemplate ToNTemplate(NUInt flags = 0) const
	{
		HNTemplate hNTemplate;
		NCheck(ANTemplateToNTemplate(GetHandle(), flags, &hNTemplate));
		return FromHandle<NTemplate>(hNTemplate);
	}

	N_DEPRECATED("function is deprecated, ANTemplate allows only anvlStandard validation level")
	ANValidationLevel GetValidationLevel() const
	{
		ANValidationLevel value;
		NCheck(ANTemplateGetValidationLevel(GetHandle(), &value));
		return value;
	}

	bool GetIsValidated() const
	{
		NBool value;
		NCheck(ANTemplateIsValidated(GetHandle(), &value));
		return value != 0;
	}

	bool CheckValidity()
	{
		NBool value;
		NCheck(ANTemplateCheckValidity(GetHandle(), &value));
		return value != 0;
	}

	NVersion GetVersion() const
	{
		NVersion_ value;
		NCheck(ANTemplateGetVersion(GetHandle(), &value));
		return NVersion(value);
	}

	N_DEPRECATED("function is deprecated, use ANTemplate(const ANTemplate, NVersion, NUInt) instead")
	void SetVersion(const NVersion & value)
	{
		NCheck(ANTemplateSetVersion(GetHandle(), value.GetValue()));
	}	

	RecordCollection GetRecords()
	{
		return RecordCollection(*this);
	}

	const RecordCollection GetRecords() const
	{
		return RecordCollection(*this);
	}
	
};
#include <Core/NReDeprecate.h>
}}}

#endif // !AN_TEMPLATE_HPP_INCLUDED
