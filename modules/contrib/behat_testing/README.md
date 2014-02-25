This another module for running behat tests on Drupal.

To use, copy behat.yml out of the folder and into your sites directory (sites/mysite.example.com)

Make a directory at sites/all/tests which will house your behat feature files

Copy the boostrap directory and place at sites/all/libraries.

execute all feature tests with

    drush be

## Basic behat installation guide

This requires a basic understanding of the command line.

    cd ~
    cp /path/to/behat_testing/composer.json .
    curl http://getcomposer.org/installer | php
    php composer.phar install --prefer-source
    mv vendor /usr/share
    cd /usr/bin
    ln -s /usr/share/vendor/behat/behat/bin/behat

## Writing your first feature

Make a file called example.feature at sites/all/tests and enter the following contents:

   #features/example.feature
    Feature: Search
      Search is the most important part of a site!
    
    @search
    Scenario: Search with no test content produces no results
      Given I am on "search/node"
        And I fill in "keys" with "node"
      When I press "Search"
       Then I should see "Your search yielded no results"

    @search
    Scenario: Search with test content produces result
    Given a node of type "article" with the title "My first node" exists
      And cron has run 
      And I am on "search/node"
      And I fill in "keys" with "node"
     When I press "Search"
      Then I should not see "Your search yielded no results"
      And I should see "My first node"

Then execute the tests with:

    drush be --profile=rebuild

The translation of scenario text in the feature file to working test code happens in the DrupalContext class. As you add new scenarios you will add new functions to this class to support them.

For a better explanation of behat and how to install it read the behat docs: http://behat.org/
