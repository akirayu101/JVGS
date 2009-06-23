#ifndef JVGS_VIDEO_RENDERER_H
#define JVGS_VIDEO_RENDERER_H

#include "../math/Vector2D.h"
#include "../math/Noise.h"
#include <SDL/SDL_opengl.h>
#include <vector>

namespace jvgs
{
    namespace video
    {
        class VideoManager;

        /** A class to draw primitives fast.
         */
        class Renderer
        {
            public:
                /** Types of primives that can be rendered.
                 */
                enum Type
                {
                    LINES = GL_LINES,
                    LINE_STRIP = GL_LINE_STRIP,
                    LINE_LOOP = GL_LINE_LOOP,
                    QUADS = GL_QUADS,
                    POLYGON = GL_POLYGON,
                    CONCAVE_POLYGON
                };

            protected:
                /** If we are between a begin() and an end() call.
                 */
                bool busy;

                /** Type currently rendering.
                 */
                Type rendering;

                /** List of vectors to render.
                 */
                std::vector<math::Vector2D> vectorList;

                /** Noise source. */
                math::Noise *noiseX, *noiseY;

            public:
                /** Constructor.
                 */
                Renderer();

                /** Destructor.
                 */
                virtual ~Renderer();

                /** Start rendering a certain type of primitive.
                 *  @param type Type of the primitive to be rendered.
                 */
                virtual void begin(Type type);

                /** End the primitive currently being rendered.
                 */
                virtual void end();

                /** Check if we are between a begin() and an end() call.
                 */
                virtual bool isBusy() const;

                /** Add a vector to the primitive.
                 *  @param vector Vector to add to the primitive.
                 */
                virtual void vector(const math::Vector2D &vector);
        };
    };
};

#endif
