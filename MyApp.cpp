#include "MyApp.h"

namespace MyApp
{
    void RenderUI()
    {
        // declaring variables to handle input
        static char originalStr[128];
        static char keyStr[128];
        // declaring variables to handle output
        std::string encryptedStr;
        std::string decryptedStr;

        // handling input
        ImGui::InputText("Original text", originalStr, IM_ARRAYSIZE(originalStr));
        ImGui::InputText("Key", keyStr, IM_ARRAYSIZE(keyStr));

        // delcaring variables to store input
        std::string original(originalStr), key(keyStr);
        // casting input strings to uppercase
        for (auto& c : original) c = toupper(c);
        for (auto& c : key) c = toupper(c);

        // checking if key is present before encryption/decryption
        if (!key.empty())
        {
            // using same function to encrypt/decrypt because all operations are effectively the same
            encryptedStr = VernamCypher(originalStr, key);
            decryptedStr = VernamCypher(encryptedStr, key);

            // Handling output
            ImGui::Text("Encrypted text:");
            ImGui::SameLine(); ImGui::Text(encryptedStr.c_str());
            ImGui::Text("Decrypted text:");
            ImGui::SameLine(); ImGui::Text(decryptedStr.c_str());
        }
    }

    std::string VernamCypher(
        const std::string& str,
        const std::string& key)
    {
        std::string result;
        for (int i = 0, j = 0; i < str.size(); i++, j++)
        {
            if (j == key.size())
                j = 0;

            result.push_back(((str[i] - 'A') ^ (key[j] - 'A') % 26) + 'A');
        }

        return result;
    }
};
