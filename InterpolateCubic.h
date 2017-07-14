////////////////////////////////////////////////////////////////////////////////
/// 
/// Cubic interpolation routine.
///
/// Author        : zlh
/// Author e-mail : zlhmyl_@126.com
///
////////////////////////////////////////////////////////////////////////////////
//
//
////////////////////////////////////////////////////////////////////////////////
//
// License :
//
//  SoundTouch audio processing library
//  Copyright (c) Olli Parviainen
//
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _InterpolateCubic_H_
#define _InterpolateCubic_H_

#include "RateTransposer.h"
#include "STTypes.h"

namespace soundtouch
{

class InterpolateCubic : public TransposerBase
{
protected:
    virtual void resetRegisters();
    virtual int transposeMono(SAMPLETYPE *dest, 
                        const SAMPLETYPE *src, 
                        int &srcSamples);
    virtual int transposeStereo(SAMPLETYPE *dest, 
                        const SAMPLETYPE *src, 
                        int &srcSamples);
    virtual int transposeMulti(SAMPLETYPE *dest, 
                        const SAMPLETYPE *src, 
                        int &srcSamples);

    double fract;

public:
    InterpolateCubic();
};

}

#endif
