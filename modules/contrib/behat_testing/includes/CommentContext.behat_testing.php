<?php
use Behat\Behat\Context\BehatContext,
    Behat\Behat\Context\Step;

class CommentContext extends BehatContext
{
  public function __construct(array $parameters) {
    // do subcontext initialization
  }


  /**
   * @When /^I add a comment "([^"]*)"$/
   */
  public function iAddAComment($comment) {
    $user = $this->getMainContext()->getCurrentUser();
      $comment = (object) (array(
         'cid' => '',
         'pid' => '',
         'nid' => '1',
         'uid' => $user->uid,
         'subject' => 'Comment',
         'created' => time(),
         'changed' =>  time(),
         'status' => '1',
         'name' => $user->name,
         'language' => 'und',
         'node_type' => 'comment_node_article',
         'registered_name' => $user->name,
         'u_uid' => $user->uid,
         'new' => 2,
         'comment_body' => 
        array (
          'und' => 
          array (
            0 => 
            array (
              'value' => $comment,
            ),
          ),
        ),
      ));
      comment_save($comment);
/*
    return array(
      new Step\When('I fill in "edit-comment-body-und-0-value" with "' . $comment . '"'),
      new Step\When('I press "Save"')
    );
*/
  }
}
