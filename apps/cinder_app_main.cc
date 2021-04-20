#include <cinder/app/RendererGl.h>
#include "field_simulation_app.h"

using chargefield::ElectricFieldApp;

void prepareSettings(ElectricFieldApp::Settings* settings) {
    settings->setResizable(false);
}

CINDER_APP(ElectricFieldApp, ci::app::RendererGl, prepareSettings);
}
