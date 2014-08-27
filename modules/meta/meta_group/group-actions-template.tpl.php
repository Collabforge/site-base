
<div class="ui-button-sidenav">

  <?php
  foreach ($links as $link) {
    $classes = array('btn');
    if (isset($link['classes']) && is_array($link['classes'])) {
      $classes = array_merge($classes, $link['classes']);
    }
    $cls = implode(' ', $classes);
    ?>
    
    <a class="<?php echo $cls; ?>" href="<?php echo url($link['href']); ?>">
      
      <i class="icon-<?php echo $link['icon']; ?>"></i>
      <?php echo t($link['title']); ?>

    </a>


    <?php
  }
  ?>

</div>
