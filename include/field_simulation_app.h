#pragma once

#include "cinder/app/App.h"
#include "arrow.h"
#include "electric_field.h"

namespace chargefield {
    /**
     * An app for visualizing interactions between charged particles and fields.
     */
    class ElectricFieldApp : public ci::app::App {

    public:
        ElectricFieldApp();

        void draw() override;

        void update() override;


        /**
         * The method generates the initial arrows.
         * Used to initialize a container object.
         * @return a vector of Arrow objects.
         */
        std::vector<Arrow> GenerateArrowList() const;

    private:
        const int kWindowSize = 1000;
        const int kMargin = 1000;

        const int kArrowMargin = 200;
        ElectricField electric_field_;

    };
};


