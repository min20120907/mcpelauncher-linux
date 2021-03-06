#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include "Resource.h"
#include "UUID.h"
class MinecraftEventing;
class IPackTelemetry;
class FilePathManager;
class Options;
class ResourcePack;
class ResourcePackStack;
enum class ResourcePackStackType;

class IContentAccessibilityProvider {
    //
};
class IContentKeyProvider {
    //
};

class SkinPackKeyProvider : public IContentAccessibilityProvider, public IContentKeyProvider {

public:

    int filler;

    SkinPackKeyProvider();


};

class PackManifestFactory {

public:

    char filler[4];

    PackManifestFactory(IPackTelemetry&);

};

class PackSourceFactory {

public:

    char filler[0x100];

    PackSourceFactory(Options*);

};

class ResourcePackRepository {

public:

    char filler[0x28];
    ResourcePack* vanillaPack;
    char filler2[0x100];

    ResourcePackRepository(MinecraftEventing&, PackManifestFactory&, IContentAccessibilityProvider&, FilePathManager*, PackSourceFactory&);

    void addWorldResourcePacks(mcpe::string const&);

};

struct ContentTierManager {

public:

    int filler;

    ContentTierManager();

};

class ResourcePackManager : public ResourceLoader {

public:

    char filler[0x100];

    /// @symbol _ZN19ResourcePackManagerC2ESt8functionIFSsvEERK18ContentTierManager
    ResourcePackManager(std::function<mcpe::string ()> const&, ContentTierManager const&);

    void setStack(std::unique_ptr<ResourcePackStack>, ResourcePackStackType, bool);

    void onLanguageChanged();

};