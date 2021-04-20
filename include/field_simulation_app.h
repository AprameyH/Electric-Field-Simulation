#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "arrow.h"
#import "electric_field.h"

namespace chargefield {
    /**
     * An app for visualizing interactions between charged particles and fields.
     */
    class ElectricFieldApp : public ci::app::App {

    public:
        ElectricFieldApp();

        void draw() override;

        void update() override;

        const int kWindowSize = 1000;
        const int kMargin = 800;

        /**
         * The method generates the initial arrows.
         * Used to initialize a container object.
         * @return a vector of Arrow objects.
         */
        std::vector <Arrow> GenerateArrowList() const;

    private:
        ElectricField electric_field_;

    };
};


