/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp> // Include the ProfilePage header

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

/**
 * Hook the ProfilePage class to enable the comment history button.
 * 
 * We use `$modify` to extend the class and hook its `init` function
 * to modify its behavior.
 */
class $modify(MyProfilePage, ProfilePage) {
    /**
     * Hook the `init` function of the ProfilePage.
     * This is where we enable or make the button visible.
     */
    bool init(int accountID, bool isMyProfile) {
        // Call the original init function to ensure the class initializes properly.
        if (!ProfilePage::init(accountID, isMyProfile)) {
            return false;
        }

        // Log for debugging
        log::debug("ProfilePage::init hooked. Enabling the comment-history-button!");

        /**
         * Access the `comment-history-button` node using Geode's Node IDs.
         * This assumes that the button has a node ID like "comment-history-button".
         */
        auto commentHistoryButton = this->getChildByID("comment-history-button");

        // Check if the button exists and enable it
        if (commentHistoryButton) {
            commentHistoryButton->setVisible(true);   // Make the button visible
            commentHistoryButton->setEnabled(true);   // Enable the button for interaction
            log::debug("Successfully enabled the comment-history-button.");
        } else {
            log::warn("comment-history-button not found!");
        }

        return true;
    }
};
