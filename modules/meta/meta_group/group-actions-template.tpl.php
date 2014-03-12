<?php
/**
 * @file
 *       
 */
?>	 
     
	<div class="ui-button-sidenav">
         <?php if ($add_a_co_member) {  ?> 
         <a class="btn" href="/node/<?php echo $gid ?>/add/member/co-owner"><i class="icon-cog"></i> Add a co-owner</a>
           <?php } ?>
          <?php if ($send_for_revision) {  ?>      
                <a class="btn" href="/group/node/<?php echo $gid ?>/send-for-revision"><i class="icon-upload"></i> Send for revision</a> 
             <?php } ?> 
          <?php if ($add_a_member) {  ?>       
		<a class="btn btn-success" href="/node/<?php echo $gid ?>/add/member"><i class="icon-user"></i> Add a member</a>
	 <?php } ?>   
           <?php if ($join_a_group) {  ?>        
                <a class="btn btn-success" href="/group/node/<?php echo $gid ?>/subscribe"><i class="icon-plus"></i> Join this hub</a>
            <?php } ?>  
          <?php if ($leave_a_group) {  ?>       
		<a class="btn btn-danger" href="/group/node/<?php echo $gid ?>/unsubscribe"><i class="icon-remove"></i> Unsubscribe from this Hub</a>
           <?php } ?>
              
	</div>

