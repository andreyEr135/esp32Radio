TEMPLATE = subdirs

SUBDIRS += MapGraphics \
    WiFiRadioConfig

WiFiRadioConfig.depends += MapGraphics
