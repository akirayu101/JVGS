#ifndef JVGS_FONT_FONT_H
#define JVGS_FONT_FONT_H

#include <string>
#include "../sketch/Sketch.h"
#include "../math/Vector2D.h"
#include "../math/AffineTransformationMatrix.h"
#include "../video/ListManager.h"
#include <ft2build.h>
#include FT_FREETYPE_H

namespace jvgs
{
    namespace font
    {
        class Font
        {
            private:
                /** Number of characters. */
#               ifndef SWIG
                    const static int NUMBER_OF_CHARACTERS;
#               else
                    static int NUMBER_OF_CHARACTERS;
#               endif

                /** Font size. */
                float size;

                /** Advance per character. Used to calculate text width. */
                float *advances;

                /** Transformation matrix for points. */
                math::AffineTransformationMatrix matrix;

                /** Base list. */
                video::ListManager::List base;

            public:
                /** Constructor.
                 *  @param fileName File name of the font to load.
                 *  @param size Pixel size for the font.
                 */
                Font(const std::string &fileName, float size);

                /** Destructor.
                 */
                virtual ~Font();

                /** Draw a string to screen.
                 *  @param string String to draw.
                 */
                void drawString(const std::string &string) const;

                /** Calculate the width of a string when drawn.
                 *  @param string String to calculate width for.
                 *  @return The string width.
                 */
                float getStringWidth(const std::string &string) const;

            protected:
                /** Create a sketch group from a given freetype outline.
                 *  @param outline Outline to create a sketch from.
                 *  @return The outline as a group.
                 */
                virtual sketch::Group *createSketchGroup(FT_Outline *outline)
                        const;

                /** Convert a freetype vector to a jvgs vector.
                 *  @param point Freetype vector to convert.
                 *  @return The converted vector.
                 */
                virtual math::Vector2D toVector(const FT_Vector &point) const;
        };
    }
}

#endif
