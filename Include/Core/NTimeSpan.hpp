#ifndef N_TIME_SPAN_HPP_INCLUDED
#define N_TIME_SPAN_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <Core/NError.hpp>
namespace Neurotec
{
#include <Core/NTimeSpan.h>
}
#if defined(N_FRAMEWORK_MFC)
	#include <atltime.h>
	typedef CTimeSpan NTimeSpanType;
#elif defined(N_FRAMEWORK_WX)
	#include <wx/datetime.h>
	typedef wxTimeSpan NTimeSpanType;
#elif defined(N_FRAMEWORK_QT)
	#include <QTime>
	typedef QTime NTimeSpanType;
#endif

namespace Neurotec
{
#undef N_TIME_SPAN_TICKS_PER_MILLISECOND
#undef N_TIME_SPAN_TICKS_PER_SECOND
#undef N_TIME_SPAN_TICKS_PER_MINUTE
#undef N_TIME_SPAN_TICKS_PER_HOUR
#undef N_TIME_SPAN_TICKS_PER_DAY

const NLong N_TIME_SPAN_TICKS_PER_MILLISECOND =        10000LL;
const NLong N_TIME_SPAN_TICKS_PER_SECOND      =     10000000LL;
const NLong N_TIME_SPAN_TICKS_PER_MINUTE      =    600000000LL;
const NLong N_TIME_SPAN_TICKS_PER_HOUR        =  36000000000LL;
const NLong N_TIME_SPAN_TICKS_PER_DAY         = 864000000000LL;

class NTimeSpan
{
	N_DECLARE_COMPARABLE_BASIC_CLASS(NTimeSpan)

public:
	static bool IsTimeValid(NInt days, NInt hours, NInt minutes, NInt seconds, NInt milliseconds)
	{
		return NTimeSpanIsTimeValid(days, hours, minutes, seconds, milliseconds) != 0;
	}

	static NTimeSpan FromTicks(NLong value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromTicks(value, &v));
		return NTimeSpan(v);
	}

	static NTimeSpan FromDays(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromDays(value, &v));
		return NTimeSpan(v);
	}

	static NTimeSpan FromHours(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromHours(value, &v));
		return NTimeSpan(v);
	}

	static NTimeSpan FromMinutes(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromMinutes(value, &v));
		return NTimeSpan(v);
	}

	static NTimeSpan FromSeconds(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromSeconds(value, &v));
		return NTimeSpan(v);
	}

	static NTimeSpan FromMilliseconds(NDouble value)
	{
		NTimeSpan_ v;
		NCheck(NTimeSpanCreateFromMilliseconds(value, &v));
		return NTimeSpan(v);
	}

	static NInt Compare(NTimeSpan value1, NTimeSpan value2)
	{
		NInt result;
		NCheck(NTimeSpanCompare(value1.value, value2.value, &result));
		return result;
	}

	NTimeSpan(NInt days, NInt hours, NInt minutes, NInt seconds, NInt milliseconds)
	{
		NCheck(NTimeSpanCreate(days, hours, minutes, seconds, milliseconds, &value));
	}

#if defined(N_FRAMEWORK_MFC)
	NTimeSpan(CTimeSpan value)
	{
		NLong theValue = (NLong)(value.GetTimeSpan());
		if (theValue < N_TIME_SPAN_MIN / N_TIME_SPAN_TICKS_PER_SECOND || N_TIME_SPAN_MAX / N_TIME_SPAN_TICKS_PER_SECOND < theValue) NThrowOverflowException();
		this->value = theValue * N_TIME_SPAN_TICKS_PER_SECOND;
	}
#elif defined(N_FRAMEWORK_WX)
	NTimeSpan(wxTimeSpan value)
	{
		NLong theValue = (NLong)value.GetMilliseconds().GetValue();
		if (theValue < N_TIME_SPAN_MIN / N_TIME_SPAN_TICKS_PER_MILLISECOND || N_TIME_SPAN_MAX / N_TIME_SPAN_TICKS_PER_MILLISECOND < theValue) NThrowOverflowException();
		this->value = theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND;
	}
#elif defined(N_FRAMEWORK_QT)
	NTimeSpan(QTime value)
	{
		this->value = QTime().msecsTo(value) * N_TIME_SPAN_TICKS_PER_MILLISECOND;
	}
#endif

	bool IsValid() const
	{
		return NTimeSpanIsValid(value) != 0;
	}

	NTimeSpan Add(NTimeSpan nTimeSpan) const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanAdd(this->value, nTimeSpan.value, &result));
		return NTimeSpan(result);
	}

	NTimeSpan Subtract(NTimeSpan nTimeSpan) const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanSubtract(this->value, nTimeSpan.value, &result));
		return NTimeSpan(result);
	}

	NInt CompareTo(NTimeSpan nTimeSpan) const
	{
		NInt result;
		NCheck(NTimeSpanCompare(this->value, nTimeSpan.value, &result));
		return result;
	}

	NTimeSpan Negate() const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanNegate(this->value, &result));
		return NTimeSpan(result);
	}

	NTimeSpan Duration() const
	{
		NTimeSpan_ result;
		NCheck(NTimeSpanDuration(this->value, &result));
		return NTimeSpan(result);
	}

	void Decode(NInt * pDays, NInt * pHours, NInt * pMinutes, NInt * pSeconds, NInt * pMilliseconds) const
	{
		NCheck(NTimeSpanDecode(value, pDays, pHours, pMinutes, pSeconds, pMilliseconds));
	}

	NString ToString(const NStringWrapper & format = NString()) const
	{
		HNString hValue;
		NCheck(NTimeSpanToStringN(value, format.GetHandle(), &hValue));
		return NString(hValue, true);
	}

	NLong GetTicks() const
	{
		NLong ticks;
		NCheck(NTimeSpanGetTicks(this->value, &ticks));
		return ticks;
	}

	NInt GetDays() const
	{
		NInt days;
		NCheck(NTimeSpanGetDays(this->value, &days));
		return days;
	}

	NInt GetHours() const
	{
		NInt hours;
		NCheck(NTimeSpanGetHours(this->value, &hours));
		return hours;
	}

	NInt GetMinutes() const
	{
		NInt minutes;
		NCheck(NTimeSpanGetMinutes(this->value, &minutes));
		return minutes;
	}

	NInt GetSeconds() const
	{
		NInt seconds;
		NCheck(NTimeSpanGetSeconds(this->value, &seconds));
		return seconds;
	}

	NInt GetMilliseconds() const
	{
		NInt milliseconds;
		NCheck(NTimeSpanGetMilliseconds(this->value, &milliseconds));
		return milliseconds;
	}

	NDouble GetTotalDays() const
	{
		NDouble totalDays;
		NCheck(NTimeSpanGetTotalDays(this->value, &totalDays));
		return totalDays;
	}

	NDouble GetTotalHours() const
	{
		NDouble totalHours;
		NCheck(NTimeSpanGetTotalHours(this->value, &totalHours));
		return totalHours;
	}

	NDouble GetTotalMinutes() const
	{
		NDouble totalMinutes;
		NCheck(NTimeSpanGetTotalMinutes(this->value, &totalMinutes));
		return totalMinutes;
	}

	NDouble GetTotalSeconds() const
	{
		NDouble totalSeconds;
		NCheck(NTimeSpanGetTotalSeconds(this->value, &totalSeconds));
		return totalSeconds;
	}

	NDouble GetTotalMilliseconds() const
	{
		NDouble totalMilliseconds;
		NCheck(NTimeSpanGetTotalMilliseconds(this->value, &totalMilliseconds));
		return totalMilliseconds;
	}

	NTimeSpan operator+(const NTimeSpan & nTimeSpan) const
	{
		return Add(nTimeSpan);
	}

	NTimeSpan operator-(const NTimeSpan & nTimeSpan) const
	{
		return Subtract(nTimeSpan);
	}

	NTimeSpan operator-() const
	{
		return Negate();
	}

	NTimeSpan operator+() const
	{
		return *this;
	}

#if defined(N_FRAMEWORK_MFC)
	operator CTimeSpan() const
	{
		NLong theValue = value / N_TIME_SPAN_TICKS_PER_SECOND;
		if (value >= 0 && value - theValue * N_TIME_SPAN_TICKS_PER_SECOND >= N_TIME_SPAN_TICKS_PER_SECOND / 2)
		{
			theValue++;
		}
		else if (value < 0 && value - theValue * N_TIME_SPAN_TICKS_PER_SECOND <= -N_TIME_SPAN_TICKS_PER_SECOND / 2)
		{
			theValue--;
		}
		return CTimeSpan((__time64_t)theValue);
	}
#elif defined(N_FRAMEWORK_WX)
	operator wxTimeSpan() const
	{
		NLong theValue = value / N_TIME_SPAN_TICKS_PER_MILLISECOND;
		if (theValue < N_INT_MIN || theValue > N_INT_MAX) NThrowOverflowException();
		if (value >= 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND >= N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue == N_INT_MAX) NThrowOverflowException();
			theValue++;
		}
		else if (value < 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND <= -N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue == N_INT_MIN) NThrowOverflowException();
			theValue--;
		}
		return wxTimeSpan::Milliseconds((long)theValue);
	}
#elif defined(N_FRAMEWORK_QT)
	operator QTime() const
	{
		NLong theValue = value / N_TIME_SPAN_TICKS_PER_MILLISECOND;
		if (theValue < -86400000 || theValue > 86400000) NThrowOverflowException();
		if (value >= 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND >= N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue > 86400000) NThrowOverflowException();
			theValue++;
		}
		else if (value < 0 && value - theValue * N_TIME_SPAN_TICKS_PER_MILLISECOND <= -N_TIME_SPAN_TICKS_PER_MILLISECOND / 2)
		{
			if (theValue < -86400000) NThrowOverflowException();
			theValue--;
		}
		return QTime().addMSecs((int)theValue);
	}
#endif
};

#undef N_TIME_SPAN_MIN
#undef N_TIME_SPAN_MAX
const NTimeSpan N_TIME_SPAN_MIN(N_LONG_MIN);
const NTimeSpan N_TIME_SPAN_MAX(N_LONG_MAX);
}

#endif // !N_TIME_SPAN_HPP_INCLUDED
