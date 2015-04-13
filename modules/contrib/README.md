This is a small API module that may be used by other modules to
generate a hint string intended for insertion into the project's
`hook_help`. It has no adminsitrative UI and will not do anything by
itself; install this module only if some other module tells you to.

The hint string may point to online documentation, the project's
`README.md` or `README.txt`, or help texts provided by **Advanced
help**

I created this module because I found that I've replicated the *same*
pattern in `hook_help` in *every* Drupal module I maintain.
Replicated patterns consumes memory, and are harder to maintain.
Instead, to make use of this pattern, call the function this module
provides.

The major features of **Advanced help hint** are:

1. If **Advanced help** is not enabled, and you've indicated that
   there are helps file in your repo, it will suggest that it is
   enabled.

2. If **Advanced help** is enabled, it will generate a link to
   whatever help it makes available.

3. If you tell it that online documentation for your module exists, it
   will generate a link to that as well.


## Recommended modules

* [Advanced Help][1]:<br>
  When this module is enabled, help files created with its framework
  will become available, or `README.md` or `README.txt` will be
  available in the sites's adminsitrative UI.
* [Markdown filter][2]:<br>
  When this module is enabled, display of the project's `README.md`
  will be rendered with the markdown filter.


# Installation

This is an API for other modules.  It will not do anything by
itself. Install this module only if some other module tells you to.

1. Install as you would normally install a contributed drupal
   module. See: [Installing modules][3] for further information.

2. Edit your own module's `hook_help` to make use of the result of
   calling `advanced_help_hint_docs`.  For details, see the API
   section below.

# Configuration

This module has no adminsitrative or other UI.  It will usually only
be enabled if listed as a dependency by some other module.

# API

If you want to make use of this module, first make it a dependency in
your module's .info-file.  You do that with the following line:

    dependencies[] = advanced_help_hint

The module only provides a single function:

    advanced_help_hint_docs($project, $doclink = NULL, $repo = FALSE)

## Parameters

**$project**: String.  The name of your module or theme.

**$doclink**: String. An URL to online documentation, for example
community documentation about your project on Drupal.org.

**$repo**: Boolean. Set this TRUE if your project makes use of the
[**Advanced help**][1] framework to have have online help, or includes
a `README.md` or `README.txt` help file.

## Return value

A string with the generated hint text.

## Examples

Provided your module is named “mymodule”, here are some examples of
how to call `advanced_help_hint_docs` inside `hook_help`:

Example 1: Online documentation exists on the following URL
“https://www.drupal.org/node/2024005”:

    function mymodule_help($path, $arg) {
      if ($path == 'admin/help#mymodule') {
        return '<p>' . t('Some short description the module.') . '</p>' .
          '<p>' .
          advanced_help_hint_docs('mymodule', 'https://www.drupal.org/node/2461745') .
         '</p>';
      }
    }

Example 2: Documentation is provided in a file named “README.md”,
“README.txt” or a subdirectory “help” included in the repo:

    function mymodule_help($path, $arg) {
      if ($path == 'admin/help#mymodule') {
        return '<p>' . t('Some short description the module.') . '</p>' .
          '<p>' . advanced_help_hint_docs('mymodule', NULL, TRUE) . '</p>';
      }
    }

# Maintainers

Project is maintained by [gisle][4] (Gisle Hannemyr).

Any help with development (patches, reviews, comments) are welcome.

Development has been sponsored by [Hannemyr Nye Medier AS][5].

[1]: https://www.drupal.org/project/advanced_help
[2]: https://www.drupal.org/project/markdown
[3]: https://drupal.org/documentation/install/modules-themes/modules-7
[4]: https://www.drupal.org/u/gisle
[5]: http://hannemyr.com/hnm/