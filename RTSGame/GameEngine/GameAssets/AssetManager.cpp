#include "AssetManager.h"
#include <assert.h>

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
	assert(sInstance == nullptr);
	sInstance = this;
}

sf::Texture & AssetManager::GetTexture(std::string const & filename)
{
	auto& texMap = sInstance->m_Textures;
	auto pairFound = texMap.find(filename);
	if (pairFound != texMap.end()) {
		return pairFound->second;
	}
	else {
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

sf::SoundBuffer & AssetManager::GetSoundBuffer(std::string const & filename)
{
	auto& sBufferMap = sInstance->m_SoundBuffers;

	auto pairFound = sBufferMap.find(filename);
	if (pairFound != sBufferMap.end()) {
		return pairFound->second;
	}
	else {
		auto& sBuffer = sBufferMap[filename];
		sBuffer.loadFromFile(filename);
		return sBuffer;
	}
}

sf::Music & AssetManager::GetMusic(std::string const & filename)
{
	auto& MusicMap = sInstance->m_Music;

	auto pairFound = MusicMap.find(filename);
	if (pairFound != MusicMap.end()) {
		return pairFound->second;
	}
	else {
		auto& music = MusicMap[filename];
		music.openFromFile(filename);
		return music;
	}
}

sf::Font & AssetManager::GetFont(std::string const & filename)
{
	auto& fontMap = sInstance->m_Fonts;

	auto pairFound = fontMap.find(filename);
	if (pairFound != fontMap.end()) {
		return pairFound->second;
	}
	else {
		auto& font = fontMap[filename];
		font.loadFromFile(filename);
		return font;
	}
}

sf::Shader * AssetManager::GetShader(std::string const & vsFile, std::string const & fsFile)
{
	auto& shaderMap = sInstance->m_Shaders;

	auto combinedKey = vsFile + ";" + fsFile;
	auto pairFound = shaderMap.find(combinedKey);
	if (pairFound != shaderMap.end()) {
		return pairFound->second.get();
	}
	else {
		auto& shader = (shaderMap[combinedKey] = std::unique_ptr<sf::Shader>(new sf::Shader()));
		shader->loadFromFile(vsFile, fsFile);
		return shader.get();
	}
}


