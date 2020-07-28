#ifndef NL_ATTRIBUTES_H_INCLUDED
#define NL_ATTRIBUTES_H_INCLUDED

#include <Biometrics/NBiometricAttributes.h>
#include <Biometrics/NLTemplate.h>
#include <Geometry/NGeometry.h>
#include <Images/NImage.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NLAttributes, NBiometricAttributes)

NResult N_API NLAttributesCreate(HNLAttributes * phAttributes);

NResult N_API NLAttributesGetTemplate(HNLAttributes hAttributes, HNLTemplate * phValue);
NResult N_API NLAttributesSetTemplate(HNLAttributes hAttributes, HNLTemplate hTemplate);
NResult N_API NLAttributesGetBoundingRect(HNLAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NLAttributesSetBoundingRect(HNLAttributes hAttributes, const struct NRect_ * pValue);
NResult N_API NLAttributesGetYaw(HNLAttributes hAttributes, NFloat * pValue);
NResult N_API NLAttributesSetYaw(HNLAttributes hAttributes, NFloat value);
NResult N_API NLAttributesGetPitch(HNLAttributes hAttributes, NFloat * pValue);
NResult N_API NLAttributesSetPitch(HNLAttributes hAttributes, NFloat value);
NResult N_API NLAttributesSetRoll(HNLAttributes hAttributes, NFloat value);
NResult N_API NLAttributesGetRoll(HNLAttributes hAttributes, NFloat * pValue);

NResult N_API NLAttributesGetSharpness(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetSharpness(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetBackgroundUniformity(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetBackgroundUniformity(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetGrayscaleDensity(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetGrayscaleDensity(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetSaturation(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetSaturation(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetContrast(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetContrast(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetNoise(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetNoise(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetRightEyeCenter(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesSetRightEyeCenter(HNLAttributes hAttributes, const NLFeaturePoint * pValue);
NResult N_API NLAttributesGetLeftEyeCenter(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesSetLeftEyeCenter(HNLAttributes hAttributes, const NLFeaturePoint * pValue);
NResult N_API NLAttributesGetNoseTip(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesSetNoseTip(HNLAttributes hAttributes, const NLFeaturePoint * pValue);
NResult N_API NLAttributesGetMouthCenter(HNLAttributes hAttributes, NLFeaturePoint * pValue);
NResult N_API NLAttributesSetMouthCenter(HNLAttributes hAttributes, const NLFeaturePoint * pValue);

NResult N_API NLAttributesGetGender(HNLAttributes hAttributes, NGender * pValue);
NResult N_API NLAttributesSetGender(HNLAttributes hAttributes, NGender value);
NResult N_API NLAttributesGetGenderConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetGenderConfidence(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetExpression(HNLAttributes hAttributes, NLExpression * pValue);
NResult N_API NLAttributesSetExpression(HNLAttributes hAttributes, NLExpression value);
NResult N_API NLAttributesGetExpressionConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetExpressionConfidence(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetProperties(HNLAttributes hAttributes, NLProperties * pValue);
NResult N_API NLAttributesSetProperties(HNLAttributes hAttributes, NLProperties value);
NResult N_API NLAttributesGetGlassesConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetGlassesConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetDarkGlassesConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetDarkGlassesConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetBlinkConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetBlinkConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetLookingAwayConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetLookingAwayConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetRedEyeConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetRedEyeConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetFaceDarknessConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetFaceDarknessConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetUnnaturalSkinToneConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetUnnaturalSkinToneConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetSkinReflectionConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetSkinReflectionConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetGlassesReflectionConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetGlassesReflectionConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetWashedOutConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetWashedOutConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetPixelationConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetPixelationConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetMouthOpenConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetMouthOpenConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetBeardConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetBeardConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetMustacheConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetMustacheConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetHatConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetHatConfidence(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetEmotionNeutralConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionNeutralConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionAngerConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionAngerConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionContemptConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionContemptConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionDisgustConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionDisgustConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionFearConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionFearConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionHappinessConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionHappinessConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionSadnessConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionSadnessConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEmotionSurpriseConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEmotionSurpriseConfidence(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetAge(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetAge(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetEthnicityWhiteConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEthnicityWhiteConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEthnicityBlackConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEthnicityBlackConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEthnicityAsianConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEthnicityAsianConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEthnicityIndianConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEthnicityIndianConfidence(HNLAttributes hAttributes, NByte value);
NResult N_API NLAttributesGetEthnicityHispanicConfidence(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesSetEthnicityHispanicConfidence(HNLAttributes hAttributes, NByte value);

NResult N_API NLAttributesGetBaseFrameIndex(HNLAttributes hAttributes, NInt * pValue);
NResult N_API NLAttributesSetBaseFrameIndex(HNLAttributes hAttributes, NInt value);

NResult N_API NLAttributesGetThumbnail(HNLAttributes hAttributes, HNImage * phValue);
NResult N_API NLAttributesSetThumbnail(HNLAttributes hAttributes, HNImage hValue);

NResult N_API NLAttributesGetFeaturePointCount(HNLAttributes hAttributes, NInt * pValue);
NResult N_API NLAttributesGetFeaturePoint(HNLAttributes hAttributes, NInt index, struct NLFeaturePoint_ * pValue);
NResult N_API NLAttributesGetFeaturePoints(HNLAttributes hAttributes, struct NLFeaturePoint_ * * parValues, NInt * pValueCount);
NResult N_API NLAttributesGetFeaturePointCapacity(HNLAttributes hAttributes, NInt * pValue);
NResult N_API NLAttributesSetFeaturePointCapacity(HNLAttributes hAttributes, NInt value);
NResult N_API NLAttributesSetFeaturePoint(HNLAttributes hAttributes, NInt index, const struct NLFeaturePoint_ * pValue);
NResult N_API NLAttributesAddFeaturePoint(HNLAttributes hAttributes, const struct NLFeaturePoint_ * pValue, NInt * pIndex);
NResult N_API NLAttributesInsertFeaturePoint(HNLAttributes hAttributes, NInt index, const struct NLFeaturePoint_ * pValue);
NResult N_API NLAttributesRemoveFeaturePointAt(HNLAttributes hAttributes, NInt index);
NResult N_API NLAttributesClearFeaturePoints(HNLAttributes hAttributes);

NResult N_API NLAttributesGetLivenessAction(HNLAttributes hAttributes, NLivenessAction * pValue);
NResult N_API NLAttributesGetLivenessScore(HNLAttributes hAttributes, NByte * pValue);
NResult N_API NLAttributesGetLivenessTargetYaw(HNLAttributes hAttributes, NFloat * pValue);
NResult N_API NLAttributesGetLivenessTargetPitch(HNLAttributes hAttributes, NFloat * pValue);

NResult N_API NLAttributesGetTokenImageRect(HNLAttributes hAttributes, struct NRect_ * pValue);
NResult N_API NLAttributesSetTokenImageRect(HNLAttributes hAttributes, const struct NRect_ * pValue);

NResult N_API NLAttributesGetIcaoWarnings(HNLAttributes hAttributes, NIcaoWarnings * pValue);
NResult N_API NLAttributesSetIcaoWarnings(HNLAttributes hAttributes, NIcaoWarnings value);

#ifdef N_CPP
}
#endif

#endif // !NL_ATTRIBUTES_H_INCLUDED
