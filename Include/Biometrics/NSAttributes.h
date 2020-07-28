#ifndef NS_ATTRIBUTES_H_INCLUDED
#define NS_ATTRIBUTES_H_INCLUDED

#include <Biometrics/NBiometricAttributes.h>
#include <Biometrics/NSRecord.h>
#include <Core/NTimeSpan.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NSAttributes, NBiometricAttributes)

NResult N_API NSAttributesCreate(NInt phraseId, HNSAttributes * phAttributes);
NResult N_API NSAttributesCreateEx(HNSAttributes * phAttributes);

NResult N_API NSAttributesGetTemplate(HNSAttributes hAttributes, HNSRecord * phValue);
NResult N_API NSAttributesSetTemplate(HNSAttributes hAttributes, HNSRecord hValue);
NResult N_API NSAttributesGetPhraseId(HNSAttributes hAttributes, NInt * pValue);
NResult N_API NSAttributesSetPhraseId(HNSAttributes hAttributes, NInt balue);
NResult N_API NSAttributesGetVoiceStart(HNSAttributes hAttributes, NTimeSpan_ * pValue);
NResult N_API NSAttributesSetVoiceStart(HNSAttributes hAttributes, NTimeSpan_ value);
NResult N_API NSAttributesGetVoiceDuration(HNSAttributes hAttributes, NTimeSpan_ * pValue);
NResult N_API NSAttributesSetVoiceDuration(HNSAttributes hAttributes, NTimeSpan_ value);
NResult N_API NSAttributesIsVoiceDetected(HNSAttributes hAttributes, NBool * pValue);
NResult N_API NSAttributesSetIsVoiceDetected(HNSAttributes hAttributes, NBool value);
NResult N_API NSAttributesGetSoundLevel(HNSAttributes hAttributes, NDouble * pValue);
NResult N_API NSAttributesSetSoundLevel(HNSAttributes hAttributes, NDouble value);

#ifdef N_CPP
}
#endif

#endif // !NS_ATTRIBUTES_H_INCLUDED
