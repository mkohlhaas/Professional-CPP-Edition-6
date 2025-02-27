#pragma once

#include "Ford.h"
#include "ICarFactory.h"
#include <memory>

class FordFactory : public ICarFactory
{
  public:
    std::unique_ptr<ICar> makeSuv() override
    {
        return std::make_unique<FordSuv>();
    }
    std::unique_ptr<ICar> makeSedan() override
    {
        return std::make_unique<FordSedan>();
    }
};
