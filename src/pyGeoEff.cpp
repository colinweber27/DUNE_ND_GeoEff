#include "geoEff.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>

namespace py = pybind11;

PYBIND11_MODULE(pyGeoEff, m) {
    m.doc() = "DUNE ND Geometric efficiency python module";

    py::class_<throwcombo>(m, "throwcombo")
      .def(py::init<>())
      .def_property("thrownEdepspos",
        [](throwcombo& selfa){ return selfa.thrownEdepspos; },
        [](throwcombo& selfa, const std::vector< Eigen::Matrix3Xf >& valuea ){ selfa.thrownEdepspos = valuea; })
      .def_property("containresult",
        [](throwcombo& selfb){ return selfb.containresult; },
        [](throwcombo& selfb, const std::vector< std::vector< std::vector< uint64_t > > >& valueb ){ selfb.containresult = valueb; });

    py::class_<geoEff>(m, "geoEff")
      .def(py::init<int, bool>(), py::arg("seed"), py::arg("verbose")=false)
      .def("setNthrows", &geoEff::setNthrows)
      .def("setNthrowsFD", &geoEff::setNthrowsFD)
      .def("setVertex", &geoEff::setVertex)
      .def("setNDrandVertex", &geoEff::setNDrandVertex)
      .def("setVertexFD", &geoEff::setVertexFD)
      .def("setOnAxisVertex", &geoEff::setOnAxisVertex)
      .def("setOffAxisVertex", &geoEff::setOffAxisVertex)
      .def("setHitSegEdeps", &geoEff::setHitSegEdeps)
      .def("setHitSegPoss", &geoEff::setHitSegPoss)
      .def("setRangeX", &geoEff::setRangeX)
      .def("setRangeY", &geoEff::setRangeY)
      .def("setRangeZ", &geoEff::setRangeZ)
      .def("setRangeXFD", &geoEff::setRangeXFD)
      .def("setRangeYFD", &geoEff::setRangeYFD)
      .def("setRangeZFD", &geoEff::setRangeZFD)
      .def("setRandomizeX", &geoEff::setRandomizeX)
      .def("setRandomizeY", &geoEff::setRandomizeY)
      .def("setRandomizeZ", &geoEff::setRandomizeZ)
      .def("setRandomizeXFD", &geoEff::setRandomizeXFD)
      .def("setRandomizeYFD", &geoEff::setRandomizeYFD)
      .def("setRandomizeZFD", &geoEff::setRandomizeZFD)
      .def("setActiveX", &geoEff::setActiveX)
      .def("setActiveY", &geoEff::setActiveY)
      .def("setActiveZ", &geoEff::setActiveZ)
      .def("setFDActiveX", &geoEff::setFDActiveX)
      .def("setFDActiveY", &geoEff::setFDActiveY)
      .def("setFDActiveZ", &geoEff::setFDActiveZ)
      .def("setOffsetX", &geoEff::setOffsetX)
      .def("setOffsetY", &geoEff::setOffsetY)
      .def("setOffsetZ", &geoEff::setOffsetZ)
      .def("setOffAxisOffsetX", &geoEff::setOffAxisOffsetX)
      .def("setOffAxisOffsetY", &geoEff::setOffAxisOffsetY)
      .def("setOffAxisOffsetZ", &geoEff::setOffAxisOffsetZ)
      .def("setBeamDir", &geoEff::setBeamDir)
      .def("setDecayPos", &geoEff::setDecayPos)
      .def("setDecayPos4RandomThrowX", &geoEff::setDecayPos4RandomThrowX)
      .def("getDecayPos", &geoEff::getDecayPos)
      .def("setUseFixedBeamDir", &geoEff::setUseFixedBeamDir)
      .def("setVetoSizes", &geoEff::setVetoSizes)
      .def("setVetoEnergyThresholds", &geoEff::setVetoEnergyThresholds)
      .def("setMuEndV", &geoEff::setMuEndV)
      .def("setMuStartP", &geoEff::setMuStartP)
      .def("setHadronHitV", &geoEff::setHadronHitV)
      .def("throwTransforms", &geoEff::throwTransforms)
      .def("throwTransformsFD", &geoEff::throwTransformsFD)
      .def("getOffAxisMuEndV", &geoEff::getOffAxisMuEndV)
      .def("getOffAxisMuStartP", &geoEff::getOffAxisMuStartP)
      .def("getOffAxisHadronHitV", &geoEff::getOffAxisHadronHitV)
      .def("getCurrentThrowTranslationsX", &geoEff::getCurrentThrowTranslationsX)
      .def("getCurrentThrowTranslationsY", &geoEff::getCurrentThrowTranslationsY)
      .def("getCurrentThrowTranslationsZ", &geoEff::getCurrentThrowTranslationsZ)
      .def("getCurrentThrowRotations", &geoEff::getCurrentThrowRotations)
      .def("getCurrentThrowDeps", &geoEff::getCurrentThrowDeps)
      .def("getCurrentThrowDepsX", &geoEff::getCurrentThrowDepsX)
      .def("getCurrentThrowDepsY", &geoEff::getCurrentThrowDepsY)
      .def("getCurrentThrowDepsZ", &geoEff::getCurrentThrowDepsZ)
      .def("getHadronContainmentThrows", &geoEff::getHadronContainmentThrows)
      .def("getHadronContainmentOrigin", &geoEff::getHadronContainmentOrigin)
      .def("getNDContainment4RandomThrowX", &geoEff::getNDContainment4RandomThrowX)
      .def("getFDContainment4RandomThrow", &geoEff::getFDContainment4RandomThrow)
      .def("getCurrentThrowsTotE", &geoEff::getCurrentThrowsTotE)
      .def("getTotalMomentum", &geoEff::getTotalMomentum)
      .def("getDistance", &geoEff::getDistance)
      .def("getEarthCurvature", &geoEff::getEarthCurvature)
      .def("getn2fEarthCurvatureCorr", &geoEff::getn2fEarthCurvatureCorr)
      .def("getTranslations", &geoEff::getTranslations)
      .def("move2ndorigin", &geoEff::move2ndorigin)
      .def("RemainUnchanged", &geoEff::RemainUnchanged)
      .def("setSeed", &geoEff::setSeed);
}
