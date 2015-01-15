<?php
/**
 * @file
 * collabco_mentions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function collabco_mentions_default_rules_configuration() {
  $items = array();
  $items['rules_mention_notify'] = entity_import('rules_config', '{ "rules_mention_notify" : {
      "LABEL" : "Notify of mention",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mentions" ],
      "ON" : { "mentions_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : [ "mention:user:mail" ],
            "subject" : "You were mentioned",
            "message" : "Hi [mention:user:name],\\r\\n\\r\\nYou were mentioned by \\u003Ca href=\\u0022[mention:author:url]\\u0022\\u003E[mention:author:name]\\u003C\\/a\\u003E in the topic \\u003Ca href=\\u0022[mention:entity:node:url]\\u0022\\u003E[mention:entity:node:title]\\u003C\\/a\\u003E\\r\\n\\r\\nKind regards,\\r\\n[site:name]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
