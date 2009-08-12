#ifndef JVGS_CORE_PROPERTYMAP_H
#define JVGS_CORE_PROPERTYMAP_H

#include "XMLLoadable.h"
#include <string>
#include <map>

namespace jvgs
{
    namespace core
    {
        class PropertyMap: public XMLLoadable
        {
            private:
                /** Map containing the keys and values. */
                std::map<std::string, std::string> entries;

            protected:
                /* Override
                 */
                virtual void loadData(TiXmlElement *element);

            public:
                /** Constructor. Create an empty PropertyMap.
                 */
                PropertyMap();

                /** Constructor.
                 *  @param element XML element to load data from.
                 */
                PropertyMap(TiXmlElement *element);

                /** Constructor.
                 *  @param fileName XML file to load data from.
                 */
                PropertyMap(const std::string &fileName);

                /** Destructor.
                 */
                virtual ~PropertyMap();

                /** Check if a value is set for key.
                 *  @param key Key to check for existence.
                 *  @return If the key exists in the map.
                 */
                virtual bool isSet(const std::string &key);

                /** Get the value of a key.
                 *  @param key Key to get value for.
                 *  @return The value for key.
                 */
                virtual std::string get(const std::string &key);

                /** Set the value of a key.
                 *  @param key Key to set the value for.
                 *  @param value Value for key.
                 */
                virtual void set(const std::string &key,
                        const std::string &value);
        };
    }
}

#endif