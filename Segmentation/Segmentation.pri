# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")


HEADERS += ./geo.h \
    ./maxflow-v3.02.src/block.h \
    ./maxflow-v3.02.src/graph.h \
    ./segAlgorithm.h \
    ./segmentation.h \
    ./scribblearea.h \
    ./interactionsegment.h
SOURCES += ./geos.cpp \
    ./interactionsegment.cpp \
    ./main.cpp \
    ./maxflow-v3.02.src/graph.cpp \
    ./maxflow-v3.02.src/maxflow.cpp \
    ./scribblearea.cpp \
    ./segAlgorithm.cpp \
    ./segmentation.cpp
FORMS += ./segmentation.ui \
    ./interactionsegment.ui
RESOURCES += segmentation.qrc
