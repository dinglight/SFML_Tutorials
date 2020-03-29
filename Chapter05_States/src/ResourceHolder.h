#ifndef _RESOURCE_HOLDER_H_
#define _RESOURCE_HOLDER_H_
#include <string>
#include <unordered_map>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder {
public:
    void Load(Identifier id, const std::string& fileName);
    Resource& Get(Identifier id);
    const Resource& Get(Identifier id) const;
private:
    void InsertResource(Identifier id, std::unique_ptr<Resource> resource);
private:
    std::unordered_map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::Load(Identifier id, const std::string& fileName)
{
    // Create and load resource
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(fileName))
        throw std::runtime_error("ResourceHolder::Load - Failed" + fileName);
    // If loading successful, insert resource to map
    InsertResource(id, std::move(resource));
}
template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::Get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *(found->second);
}
template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::Get(Identifier id) const
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *(found->second);
}
template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::InsertResource(Identifier id, std::unique_ptr<Resource> resource) 
{
    // Insert and check success
    auto inserted = mResourceMap.emplace(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}
#endif // _RESOURCE_HOLDER_H_