// Copyright (c) 2021-2023 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "mfx_common.h"
#if defined(MFX_ENABLE_AV1_VIDEO_ENCODE)

namespace AV1EHW
{
namespace Base
{
    class SCC
        : public FeatureBase
    {
    public:
#define DECL_BLOCK_LIST\
        DECL_BLOCK(CheckAndFix)\
        DECL_BLOCK(SetDefaults)\
        DECL_BLOCK(SetFH)\
        DECL_BLOCK(ConfigureTask)
#define DECL_FEATURE_NAME "Base_SCC"
#include "av1ehw_decl_blocks.h"

    SCC(mfxU32 FeatureId)
        : FeatureBase(FeatureId)
    {}

protected:
    virtual void SetSupported(ParamSupport& par) override;
    virtual void SetInherited(ParamInheritance& par) override;
    virtual void Query1WithCaps(const FeatureBlocks& /*blocks*/, TPushQ1 Push) override;
    virtual void SetDefaults(const FeatureBlocks& blocks, TPushSD Push) override;
    virtual void InitInternal(const FeatureBlocks& /*blocks*/, TPushII Push) override;
    virtual void PostReorderTask(const FeatureBlocks& /*blocks*/, TPushPostRT Push) override;

    std::pair<mfxU32, mfxU32> CheckAndFix(mfxVideoParam& par, const EncodeCapsAv1&);
    };

} //Base
} //namespace AV1EHW

#endif //defined(MFX_ENABLE_AV1_VIDEO_ENCODE)