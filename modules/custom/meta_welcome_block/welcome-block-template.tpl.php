<?php
/**
 * @file
 * Default theme implementation for PCP block
 *
 * Available variables:
 *  $uid: Current user ID.
 *  $current_percent: From 0 to 100% of how much the profile is complete.
 *  $next_percent: The percent if the user filled the next field.
 *  $completed: How many fields the user has filled.
 *  $incomplete: The inverse of $completed, how many empty fields left.
 *  $total: Total number of fields in profile.
 *  $nextfield_title: The name of the suggested next field to fill (human readable name).
 *  $nextfield_name: The name of the suggested next field to fill (machine name).
 *  $nextfield_id: The id of the $nextfield.
 *
 * @see template_
 */
?>


<?php if ($first_time_user || $profile_completeness || !$introduce_yourself) { ?>
<style type="text/css">
    .collabco-percent-bar.profile2-profile{ width: <?php print $current_percent; ?>%; }
    .profile2-profile{ padding-left: 0%; }
</style>

    <div class="dashboard">
        <div class-"row-fluid dashboard_head">

        <div class="welcome span12">
            <h2>Getting started checklist</h2>
        </div>
            <div class="row-fluid dashbaord_head_bottom">

              <?php if ($first_time_user) { ?>
              <div class="span4 dashboard_1 first">
                <h4>Learn About this site</h4>
                    <div class="call_out">
                        <p>Pellentesque aliquam augue ut dui aliquam consequat.</p>
                        <a class="action" href="/about-this-site" title="About this site">Read More</a>
                    </div>
                </div>
           <?php } ?>

            <?php if ($profile_completeness) { ?>
                <div class="span4 dashboard_2">
                 <h4>Complete your profile</h4>
                    <div class="call_out">

                        <!-- Progress Bar -->

                       <div class="pcp-wrapper pcp-profile2 pcp-profile">
                        <div class="percent-bar">
                        <div class="collabco-percent-bar-wrapper">
                        <div class="collabco-percent-bar profile2-profile"></div>
                        </div>
                        </div>&nbsp;&nbsp; <?php  print $current_percent; ?>%
                       </div>

                        <a class="action" href="user/<?php print $user->uid; ?>/edit/profile" title="Edit your Profile">Edit Your Profile</a>

                    </div>
                </div>
         <?php } ?>

        <?php if(!$introduce_yourself) { ?>
                <div class="span4 dashboard_3 last">
                 <h4>Introduce Yourself</h4>
                    <div class="call_out">
                    <p>
                        Post a reply to "Introduce Yourself" topic.
                    </p>

                        <a class="action" href="/news-update/welcome-please-introduce-yourself">Go There</a>

                    </div>
                </div>
        <?php } ?>

            </div>

    </div>
</div>
 <?php } ?>
