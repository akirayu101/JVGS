#include "MPathCommandParser.h"
#include "PathComponent.h"
#include "Path.h"
#include "PathDataParser.h"

#include "../math/Vector2D.h"
using namespace jvgs::math;

using namespace std;

namespace jvgs
{
    namespace sketch
    {
        MPathCommandParser::MPathCommandParser()
        {
        }

        MPathCommandParser::~MPathCommandParser()
        {
        }

        void MPathCommandParser::parse(Path *path, char command,
                PathDataParser *dataParser, const vector<float> &arguments)
                const
        {
            Vector2D translation(arguments[0], arguments[1]);
            translation = dataParser->toAbsoluteSpace(command, translation);

            dataParser->setStartingPoint(translation);
            dataParser->setCurrentPoint(translation);
            dataParser->setLastControlPoint(translation);

            PathComponent *component = new PathComponent(path);
            path->addComponent(component);
            dataParser->setCurrentComponent(component);

            /* TODO: other arguments should be treated as implicit
             * L commands. */
        }
    }
}
