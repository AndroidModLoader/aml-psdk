#ifndef __AML_PSDK_GTARGBA_H
#define __AML_PSDK_GTARGBA_H

#include <aml-psdk/sdk_basetypes.h>

#define RWRGBALONG(r, g, b, a) ((u32) (((a) << 24) | ((b) << 16) | ((g) << 8) | (r)))


struct CRGBA
{
    union
    {
        struct
        {
            unsigned char r, g, b, a;
        };
        struct
        {
            unsigned char red, green, blue, alpha;
        };
    };

    CRGBA()
    {
        Set(0, 0, 0, 0);
    }
    CRGBA(unsigned char _r, unsigned char _g, unsigned char _b)
    {
        Set(_r, _g, _b, 255);
    }
    CRGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
    {
        Set(_r, _g, _b, _a);
    }
    CRGBA(unsigned int intValue)
    {
        Set(intValue);
    }

    inline void Set(unsigned char _r, unsigned char _g, unsigned char _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
    inline void Set(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
    {
        Set(_r, _g, _b);
        a = _a;
    }
    inline void Set(unsigned int intValue)
    {
        r = (intValue >> 24) & 0xFF;
        g = (intValue >> 16) & 0xFF;
        b = (intValue >> 8) & 0xFF;
        a = intValue & 0xFF;
    }
    inline void Set(CRGBA const& rhs)
    {
        Set(rhs.r, rhs.g, rhs.b, rhs.a);
    }
    inline void Set(CRGBA const& rhs, unsigned char alpha)
    {
        Set(rhs.r, rhs.g, rhs.b, alpha);
    }
    inline unsigned int ToInt() const
    {
        return a | (b << 8) | (g << 16) | (r << 24);
    }
    inline unsigned int ToIntARGB() const
    {
        return b | (g << 8) | (r << 16) | (a << 24);
    }
    inline void FromARGB(unsigned int intValue)
    {
        a = (intValue >> 24) & 0xFF;
        r = (intValue >> 16) & 0xFF;
        g = (intValue >> 8) & 0xFF;
        b = intValue & 0xFF;
    }
    inline unsigned int ToIntABGR() const
    {
        return r | ((u32)g << 8) | ((u32)b << 16) | ((u32)a << 24);
    }
    inline void FromABGR(unsigned int intValue)
    {
        r = intValue & 0xFF;
        g = (intValue >> 8) & 0xFF;
        b = (intValue >> 16) & 0xFF;
        a = (intValue >> 24) & 0xFF;
    }
    static inline CRGBA Lerp(CRGBA const& from, CRGBA const& to, float progress)
    {
        if(!(progress > 0.0f)) return from;
        if(progress >= 1.0f) return to;
        return CRGBA(from.r + (to.r - from.r) * progress,
                     from.g + (to.g - from.g) * progress,
                     from.b + (to.b - from.b) * progress,
                     from.a + (to.a - from.a) * progress);
    }
    inline void Invert()
    {
        Set(255 - r, 255 - g, 255 - b);
    }
    inline CRGBA Inverted() const
    {
        CRGBA invertedColor = *this;
        invertedColor.Invert();
        return invertedColor;
    }
    inline CRGBA ToRGB() const
    {
        return CRGBA(r, g, b, 255);
    }

    inline bool operator==(CRGBA const &rhs) const
    {
        return r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a;
    }
    inline bool operator!=(CRGBA const &rhs) const
    {
        return !(*this == rhs);
    }
    inline void operator+=(const CRGBA& rhs)
    {
        r = std_min(r + rhs.r, 255);
        g = std_min(g + rhs.g, 255);
        b = std_min(b + rhs.b, 255);
        a = std_min(a + rhs.a, 255);
    }
    inline void operator-=(const CRGBA& rhs)
    {
        r = std_max(r - rhs.r, 0);
        g = std_max(g - rhs.g, 0);
        b = std_max(b - rhs.b, 0);
        a = std_max(a - rhs.a, 0);
    }
    inline CRGBA operator*(const float val)
    {
        CRGBA ret = *this;
        ret.r *= val;
        ret.g *= val;
        ret.b *= val;
        return ret;
    }
    inline CRGBA& operator*=(const float val)
    {
        *this = *this * val;
        return *this;
    }
};

#endif // __AML_PSDK_GTARGBA_H
