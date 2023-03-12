// Copyright 2023 DreamWorks Animation LLC
// SPDX-License-Identifier: Apache-2.0


#include "attributes.cc"
#include "SwitchColorMap_ispc_stubs.h"

#include <moonray/rendering/shading/MapApi.h>

using namespace scene_rdl2::math;
using namespace moonray::shading;

//---------------------------------------------------------------------------

RDL2_DSO_CLASS_BEGIN(SwitchColorMap, scene_rdl2::rdl2::Map)

public:
    SwitchColorMap(const scene_rdl2::rdl2::SceneClass& sceneClass, const std::string& name);
    ~SwitchColorMap();
    virtual void update();

private:
    static void sample(const scene_rdl2::rdl2::Map* self, moonray::shading::TLState *tls,
                       const moonray::shading::State& state, Color* sample);

    std::vector<scene_rdl2::rdl2::AttributeKey<scene_rdl2::rdl2::Rgb>> mInputAttrs;

RDL2_DSO_CLASS_END(SwitchColorMap)

//---------------------------------------------------------------------------

SwitchColorMap::SwitchColorMap(const scene_rdl2::rdl2::SceneClass& sceneClass, const std::string& name) :
    Parent(sceneClass, name)
{
    mSampleFunc = SwitchColorMap::sample;
    mSampleFuncv = (scene_rdl2::rdl2::SampleFuncv) ispc::SwitchColorMap_getSampleFunc();
}

SwitchColorMap::~SwitchColorMap()
{
}

void
SwitchColorMap::update()
{
    mInputAttrs.push_back(attrInput0);
    mInputAttrs.push_back(attrInput1);
    mInputAttrs.push_back(attrInput2);
    mInputAttrs.push_back(attrInput3);
    mInputAttrs.push_back(attrInput4);
    mInputAttrs.push_back(attrInput5);
    mInputAttrs.push_back(attrInput6);
    mInputAttrs.push_back(attrInput7);
    mInputAttrs.push_back(attrInput8);
    mInputAttrs.push_back(attrInput9);

    mInputAttrs.push_back(attrInput10);
    mInputAttrs.push_back(attrInput11);
    mInputAttrs.push_back(attrInput12);
    mInputAttrs.push_back(attrInput13);
    mInputAttrs.push_back(attrInput14);
    mInputAttrs.push_back(attrInput15);
    mInputAttrs.push_back(attrInput16);
    mInputAttrs.push_back(attrInput17);
    mInputAttrs.push_back(attrInput18);
    mInputAttrs.push_back(attrInput19);

    mInputAttrs.push_back(attrInput20);
    mInputAttrs.push_back(attrInput21);
    mInputAttrs.push_back(attrInput22);
    mInputAttrs.push_back(attrInput23);
    mInputAttrs.push_back(attrInput24);
    mInputAttrs.push_back(attrInput25);
    mInputAttrs.push_back(attrInput26);
    mInputAttrs.push_back(attrInput27);
    mInputAttrs.push_back(attrInput28);
    mInputAttrs.push_back(attrInput29);

    mInputAttrs.push_back(attrInput30);
    mInputAttrs.push_back(attrInput31);
    mInputAttrs.push_back(attrInput32);
    mInputAttrs.push_back(attrInput33);
    mInputAttrs.push_back(attrInput34);
    mInputAttrs.push_back(attrInput35);
    mInputAttrs.push_back(attrInput36);
    mInputAttrs.push_back(attrInput37);
    mInputAttrs.push_back(attrInput38);
    mInputAttrs.push_back(attrInput39);

    mInputAttrs.push_back(attrInput40);
    mInputAttrs.push_back(attrInput41);
    mInputAttrs.push_back(attrInput42);
    mInputAttrs.push_back(attrInput43);
    mInputAttrs.push_back(attrInput44);
    mInputAttrs.push_back(attrInput45);
    mInputAttrs.push_back(attrInput46);
    mInputAttrs.push_back(attrInput47);
    mInputAttrs.push_back(attrInput48);
    mInputAttrs.push_back(attrInput49);

    mInputAttrs.push_back(attrInput50);
    mInputAttrs.push_back(attrInput51);
    mInputAttrs.push_back(attrInput52);
    mInputAttrs.push_back(attrInput53);
    mInputAttrs.push_back(attrInput54);
    mInputAttrs.push_back(attrInput55);
    mInputAttrs.push_back(attrInput56);
    mInputAttrs.push_back(attrInput57);
    mInputAttrs.push_back(attrInput58);
    mInputAttrs.push_back(attrInput59);

    mInputAttrs.push_back(attrInput60);
    mInputAttrs.push_back(attrInput61);
    mInputAttrs.push_back(attrInput62);
    mInputAttrs.push_back(attrInput63);
}

void
SwitchColorMap::sample(const scene_rdl2::rdl2::Map* self, moonray::shading::TLState *tls,
                 const moonray::shading::State& state, Color* sample)
{
    const SwitchColorMap* me = static_cast<const SwitchColorMap*>(self);
    unsigned int choice =
            static_cast<unsigned int>(evalFloat(me, attrChoice, tls, state));
    // cycle through max choices allowed
    choice = choice % 64;
    *sample = evalColor(me, me->mInputAttrs[choice], tls, state);
}


//---------------------------------------------------------------------------

