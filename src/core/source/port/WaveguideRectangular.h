// OpenSEMBA
// Copyright (C) 2015 Salvador Gonzalez Garcia        (salva@ugr.es)
//                    Luis Manuel Diaz Angulo         (lmdiazangulo@semba.guru)
//                    Miguel David Ruiz-Cabello Nuñez (miguel@semba.guru)
//                    Daniel Mateos Romero            (damarro@semba.guru)
//
// This file is part of OpenSEMBA.
//
// OpenSEMBA is free software: you can redistribute it and/or modify it under
// the terms of the GNU Lesser General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// OpenSEMBA is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
// details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with OpenSEMBA. If not, see <http://www.gnu.org/licenses/>.

#ifndef SEMBA_SOURCE_PORT_WAVEGUIDERECTANGULAR_H_
#define SEMBA_SOURCE_PORT_WAVEGUIDERECTANGULAR_H_

#include "Waveguide.h"

namespace SEMBA {
namespace Source {
namespace Port {

class WaveguideRectangular: public Waveguide {
public:
    WaveguideRectangular(
            Magnitude::Magnitude* magnitude,
            const Geometry::Element::Group<const Geometry::Surf>& elem,
            const ExcitationMode excMode,
            const std::pair<Math::UInt,Math::UInt> mode);
    WaveguideRectangular(const WaveguideRectangular&);
    virtual ~WaveguideRectangular();

    SEMBA_CLASS_DEFINE_CLONE(WaveguideRectangular);

    bool hasSameProperties(const SEMBA::Source::Base& rhs) const;

    void set(const Geometry::Element::Group<const Geometry::Elem>&);

    const std::string& getName() const;
//    Math::Real getWidth(const BoundTerminations& sym) const;
//    Math::Real getHeight(const BoundTerminations& sym) const;

//    Math::CVecR3 getOrigin(const BoundTerminations& sym) const;
//    Math::CVecR3 getWeight(
//            const Math::CVecR3& pos,
//            const BoundTerminations& sym) const;
private:
    Geometry::BoxR3 box_; // This has been included for performance.
};

} /* namespace Port */
} /* namespace Source */
} /* namespace SEMBA */

#endif /* SEMBA_SOURCE_PORT_WAVEGUIDERECTANGULAR_H_ */
