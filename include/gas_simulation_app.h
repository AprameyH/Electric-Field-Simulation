#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "gas_container.h"

namespace idealgas {

/**
 * An app for visualizing the behavior of an ideal gas.
 */
    class IdealGasApp : public ci::app::App {
    public:
        IdealGasApp();

        void draw() override;

        void update() override;

        /**
         * Checks whether the key pressed is up or down
         * and adjusts the speed of the particles accordingly.
         * @param event The key press.s
         */
        void keyDown(cinder::app::KeyEvent event) override;

        const int kWindowSize = 1000;
        const int kMargin = 800;

        /**
         * The method returns a vector of particle objects.
         * Used to initialize a container object.
         * @return a vector of Particle objects.
         */
        std::vector<Particle> GenerateParticleList() const;

    private:
        GasContainer container_;

        /**
         * The factor by which to speed up the particles
         * upon keyboard input.
         */
        const float speed_up = 1.5;
    };

}  // namespace idealgas
