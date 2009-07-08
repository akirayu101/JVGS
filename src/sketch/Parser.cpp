#include "Parser.h"
#include "Sketch.h"
#include "SketchElementParser.h"
#include "GroupParser.h"
#include "PathParser.h"
#include "Group.h"

using namespace std;

#include "../core/LogManager.h"
using namespace jvgs::core;

#include "../math/Vector2D.h"
using namespace jvgs::math;

#include "../tinyxml/tinyxml.h"

namespace jvgs
{
    namespace sketch
    {
        Parser::Parser(string fileName, Sketch *sketch)
        {
            document = new TiXmlDocument( fileName.c_str() );
            if (!document->LoadFile()) {
                LogManager::getInstance()->error(
                        "Could not load xml document: %s", fileName.c_str());
            }

            this->sketch = sketch;

            sketchElementParsers["g"] = new GroupParser(this);
            sketchElementParsers["path"] = new PathParser(this);
        }

        Parser::~Parser()
        {
            for( map<string,SketchElementParser*>::iterator iterator =
                    sketchElementParsers.begin();
                    iterator != sketchElementParsers.end(); iterator++ ) {
                delete iterator->second;
            }

            delete document;
        }

        SketchElementParser *Parser::getSketchElementParser(string tag)
        {

            map<string, SketchElementParser*>::iterator iterator =
                    sketchElementParsers.find(tag);
            if (iterator != sketchElementParsers.end())
                return iterator->second;
            else
                return 0;
        }

        void Parser::parse()
        {
            TiXmlElement *rootElement = document->RootElement();

            float width, height;
            rootElement->QueryFloatAttribute("width", &width);
            rootElement->QueryFloatAttribute("height", &height);
            sketch->setSize(Vector2D(width, height));

            GroupParser *groupParser = new GroupParser(this);

            Group *root = (Group*) groupParser->parse(0, rootElement);
            sketch->setRoot(root);

            delete groupParser;
        }
    };
};
