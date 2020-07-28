#ifndef NE_ATTRIBUTES_HPP_INCLUDED
#define NE_ATTRIBUTES_HPP_INCLUDED

#include <Biometrics/NBiometricAttributes.hpp>
#include <Biometrics/NERecord.hpp>
#include <Geometry/NGeometry.hpp>
namespace Neurotec { namespace Biometrics
{
using ::Neurotec::Geometry::NRect_;
using ::Neurotec::Geometry::NPoint_;
#include <Biometrics/NEAttributes.h>
}}

namespace Neurotec { namespace Biometrics
{

class NIris;

class NEAttributes : public NBiometricAttributes
{
	N_DECLARE_OBJECT_CLASS(NEAttributes, NBiometricAttributes)

public:
	class InnerBoundaryPointCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications< ::Neurotec::Geometry::NPoint, NEAttributes,
		NEAttributesGetInnerBoundaryPointCount, NEAttributesGetInnerBoundaryPoint, NEAttributesGetInnerBoundaryPoints,
		NEAttributesAddInnerBoundaryPointsCollectionChanged, NEAttributesRemoveInnerBoundaryPointsCollectionChanged>
	{
		InnerBoundaryPointCollection(const NEAttributes & owner)
		{
			SetOwner(owner);
		}

	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NEAttributesGetInnerBoundaryPointCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NEAttributesSetInnerBoundaryPointCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(NEAttributesSetInnerBoundaryPoint(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ::Neurotec::Geometry::NPoint & value)
		{
			NInt index;
			NCheck(NEAttributesAddInnerBoundaryPoint(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(NEAttributesInsertInnerBoundaryPoint(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NEAttributesRemoveInnerBoundaryPointAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NEAttributesClearInnerBoundaryPoints(this->GetOwnerHandle()));
		}

		friend class NEAttributes;
	};

	class OuterBoundaryPointCollection : public ::Neurotec::Collections::NCollectionWithChangeNotifications< ::Neurotec::Geometry::NPoint, NEAttributes,
		NEAttributesGetOuterBoundaryPointCount, NEAttributesGetOuterBoundaryPoint, NEAttributesGetOuterBoundaryPoints,
		NEAttributesAddOuterBoundaryPointsCollectionChanged, NEAttributesRemoveOuterBoundaryPointsCollectionChanged>
	{
		OuterBoundaryPointCollection(const NEAttributes & owner)
		{
			SetOwner(owner);
		}

	public:
		NInt GetCapacity() const
		{
			NInt value;
			NCheck(NEAttributesGetOuterBoundaryPointCapacity(this->GetOwnerHandle(), &value));
			return value;
		}

		void SetCapacity(NInt value)
		{
			NCheck(NEAttributesSetOuterBoundaryPointCapacity(this->GetOwnerHandle(), value));
		}

		void Set(NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(NEAttributesSetOuterBoundaryPoint(this->GetOwnerHandle(), index, &value));
		}

		NInt Add(const ::Neurotec::Geometry::NPoint & value)
		{
			NInt index;
			NCheck(NEAttributesAddOuterBoundaryPoint(this->GetOwnerHandle(), &value, &index));
			return index;
		}

		void Insert(NInt index, const ::Neurotec::Geometry::NPoint & value)
		{
			NCheck(NEAttributesInsertOuterBoundaryPoint(this->GetOwnerHandle(), index, &value));
		}

		void RemoveAt(NInt index)
		{
			NCheck(NEAttributesRemoveOuterBoundaryPointAt(this->GetOwnerHandle(), index));
		}

		void Clear()
		{
			NCheck(NEAttributesClearOuterBoundaryPoints(this->GetOwnerHandle()));
		}

		friend class NEAttributes;
	};

private:
	static HNEAttributes Create(NEPosition position)
	{
		HNEAttributes handle;
		NCheck(NEAttributesCreate(position, &handle));
		return handle;
	}

	static HNEAttributes Create()
	{
		HNEAttributes handle;
		NCheck(NEAttributesCreateEx(&handle));
		return handle;
	}

public:
	NEAttributes()
		: NBiometricAttributes(Create(), true)
	{
	}

	explicit NEAttributes(NEPosition position)
		: NBiometricAttributes(Create(position), true)
	{
	}

	NIris GetOwner() const;

	NEPosition GetPosition() const
	{
		NEPosition value;
		NCheck(NEAttributesGetPosition(GetHandle(), &value));
		return value;
	}

	void SetPosition(NEPosition value)
	{
		NCheck(NEAttributesSetPosition(GetHandle(), value));
	}

	NInt GetImageIndex() const
	{
		NInt value;
		NCheck(NEAttributesGetImageIndex(GetHandle(), &value));
		return value;
	}

	void SetImageIndex(NInt value)
	{
		NCheck(NEAttributesSetImageIndex(GetHandle(), value));
	}

	::Neurotec::Geometry::NRect GetBoundingRect() const
	{
		::Neurotec::Geometry::NRect value;
		NCheck(NEAttributesGetBoundingRect(GetHandle(), &value));
		return value;
	}

	void SetBoundingRect(const ::Neurotec::Geometry::NRect & value)
	{
		NCheck(NEAttributesSetBoundingRect(GetHandle(), &value));
	}

	::Neurotec::Geometry::NRect GetCropRect() const
	{
		::Neurotec::Geometry::NRect value;
		NCheck(NEAttributesGetCropRect(GetHandle(), &value));
		return value;
	}

	void SetCropRect(const ::Neurotec::Geometry::NRect & value)
	{
		NCheck(NEAttributesSetCropRect(GetHandle(), &value));
	}

	NByte GetUsableIrisArea() const
	{
		NByte value;
		NCheck(NEAttributesGetUsableIrisArea(GetHandle(), &value));
		return value;
	}

	void SetUsableIrisArea(NByte value)
	{
		NCheck(NEAttributesSetUsableIrisArea(GetHandle(), value));
	}

	NByte GetIrisScleraContrast() const
	{
		NByte value;
		NCheck(NEAttributesGetIrisScleraContrast(GetHandle(), &value));
		return value;
	}

	void SetIrisScleraContrast(NByte value)
	{
		NCheck(NEAttributesSetIrisScleraContrast(GetHandle(), value));
	}

	NByte GetIrisPupilContrast() const
	{
		NByte value;
		NCheck(NEAttributesGetIrisPupilContrast(GetHandle(), &value));
		return value;
	}

	void SetIrisPupilContrast(NByte value)
	{
		NCheck(NEAttributesSetIrisPupilContrast(GetHandle(), value));
	}

	NByte GetPupilBoundaryCircularity() const
	{
		NByte value;
		NCheck(NEAttributesGetPupilBoundaryCircularity(GetHandle(), &value));
		return value;
	}

	void SetPupilBoundaryCircularity(NByte value)
	{
		NCheck(NEAttributesSetPupilBoundaryCircularity(GetHandle(), value));
	}

	NByte GetGrayScaleUtilisation() const
	{
		NByte value;
		NCheck(NEAttributesGetGrayScaleUtilisation(GetHandle(), &value));
		return value;
	}

	void SetGrayScaleUtilisation(NByte value)
	{
		NCheck(NEAttributesSetGrayScaleUtilisation(GetHandle(), value));
	}

	NByte GetIrisRadius() const
	{
		NByte value;
		NCheck(NEAttributesGetIrisRadius(GetHandle(), &value));
		return value;
	}

	void SetIrisRadius(NByte value)
	{
		NCheck(NEAttributesSetIrisRadius(GetHandle(), value));
	}

	NByte GetPupilToIrisRatio() const
	{
		NByte value;
		NCheck(NEAttributesGetPupilToIrisRatio(GetHandle(), &value));
		return value;
	}

	void SetPupilToIrisRatio(NByte value)
	{
		NCheck(NEAttributesSetPupilToIrisRatio(GetHandle(), value));
	}

	NByte GetIrisPupilConcentricity() const
	{
		NByte value;
		NCheck(NEAttributesGetIrisPupilConcentricity(GetHandle(), &value));
		return value;
	}

	void SetIrisPupilConcentricity(NByte value)
	{
		NCheck(NEAttributesSetIrisPupilConcentricity(GetHandle(), value));
	}

	NByte GetMarginAdequacy() const
	{
		NByte value;
		NCheck(NEAttributesGetMarginAdequacy(GetHandle(), &value));
		return value;
	}

	void SetMarginAdequacy(NByte value)
	{
		NCheck(NEAttributesSetMarginAdequacy(GetHandle(), value));
	}

	NByte GetSharpness() const
	{
		NByte value;
		NCheck(NEAttributesGetSharpness(GetHandle(), &value));
		return value;
	}

	void SetSharpness(NByte value)
	{
		NCheck(NEAttributesSetSharpness(GetHandle(), value));
	}

	NByte GetInterlace() const
	{
		NByte value;
		NCheck(NEAttributesGetInterlace(GetHandle(), &value));
		return value;
	}

	void SetInterlace(NByte value)
	{
		NCheck(NEAttributesSetInterlace(GetHandle(), value));
	}

	NByte GetNoCosmeticLensesConfidence() const
	{
		NByte value;
		NCheck(NEAttributesGetNoCosmeticLensesConfidence(GetHandle(), &value));
		return value;
	}

	void SetNoCosmeticLensesConfidence(NByte value)
	{
		NCheck(NEAttributesSetNoCosmeticLensesConfidence(GetHandle(), value));
	}

	bool IsInnerBoundaryAvailable() const
	{
		NBool value;
		NCheck(NEAttributesIsInnerBoundaryAvailable(GetHandle(), &value));
		return value != 0;
	}

	bool IsOuterBoundaryAvailable() const
	{
		NBool value;
		NCheck(NEAttributesIsOuterBoundaryAvailable(GetHandle(), &value));
		return value != 0;
	}

	NERecord GetTemplate() const
	{
		return GetObject<HandleType, NERecord>(NEAttributesGetTemplate, true);
	}

	void SetTemplate(const NERecord & value)
	{
		NCheck(NEAttributesSetTemplate(GetHandle(), value.GetHandle()));
	}

	InnerBoundaryPointCollection GetInnerBoundaryPoints()
	{
		return InnerBoundaryPointCollection(*this);
	}

	const InnerBoundaryPointCollection GetInnerBoundaryPoints() const
	{
		return InnerBoundaryPointCollection(*this);
	}

	OuterBoundaryPointCollection GetOuterBoundaryPoints()
	{
		return OuterBoundaryPointCollection(*this);;
	}

	const OuterBoundaryPointCollection GetOuterBoundaryPoints() const
	{
		return OuterBoundaryPointCollection(*this);;
	}
};

}}

#include <Biometrics/NIris.hpp>

namespace Neurotec { namespace Biometrics
{

inline NIris NEAttributes::GetOwner() const
{
	return NObject::GetOwner<NIris>();
}

}}

#endif // !NE_ATTRIBUTES_HPP_INCLUDED
