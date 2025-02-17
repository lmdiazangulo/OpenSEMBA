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

#include "Parser.h"

namespace SEMBA {
namespace Parser {

Parser::Parser() {
}

Parser::~Parser() {

}

Math::CVecR3 Parser::strToCartesianVector(const std::string& str) {
    std::stringstream iss(str);
    std::string sub;
    Math::CVecR3 res;
    for (std::size_t i = 0; i < 3; i++) {
        iss >> sub;
        res(i) = atof(sub.c_str());
    }
    return res;
}

bool Parser::strToBool(const std::string& value) {
    if (atoi(value.c_str()) == 1) {
        return true;
    } else {
        return false;
    }
}

void Parser::postReadOperations(Data* res) {
    if (res->mesh != NULL) {
        if (res->solver != NULL) {
            Math::Real scalingFactor =
                    res->solver->getSettings()("Geometry scaling factor").getReal();
            res->mesh->applyScalingFactor(scalingFactor);
            Solver::Settings settings = res->solver->getSettings();
            settings("Geometry scaling factor").setReal((Math::Real) 1.0);
            res->solver->setSettings(settings);
        }
    }
}

} /* namespace Parser */
} /* namespace SEMBA */
