Don't remember which feature that View is exported to? Which feature? does, and
more.

The Which feature? module provides information on which feature or module an
exportable item is exported to so you can know which feature to recreate after
modifying the configuration.

Which feature? was written and is maintained by Stuart Clark (deciphered) of
Realityloop Pty Ltd.
- http://www.realityloop.com
- http://twitter.com/realityloop



Features
--------------------------------------------------------------------------------

- Two (2) modes:
  - Table preprocess:
      Injects the Feature/Module into the exportables overview table.
  - Help:
      Uses Drupal cores Help module to display the Feature/Module on the
      exportables edit page.
- Supported exportables:
  - Bean module: Block types.
    * See for colspan issue: http://drupal.org/node/1887778
  - Chaos tool suite (ctools) module Export UI based exportables, including but
    not limited to:
    - Configuration builder module: Configuration pages.
    - Context module: Contexts.
    - Custom Formatters module: Formatters.
    - Delta module: Deltas.
    - Panels module: Mini panels and Layouts.
    - Views module: Views.
  - Commerce module: Customer profiles.
  - Custom Breadcrumbs module: Custom breadcrumbs.
  - Display Suite: Fields and View modes.
  - Drupal core Field module: Node fields.
  - Drupal core Filter module: Text formats.
  - Drupal core Image module: Image styles.
  - Drupal core Menu module: Menus.
  - Drupal core Node module: Content types.
  - Drupal core Taxonomy module: Taxonomy.
  - Drupal core User module: Permissions and Roles.
  - Meta tags module: Meta tags.
  - Page Manager module: Pages.
  - Rules module: Rules.
  - Search API: Autocomplete searches, Facets, Indexes and Servers.
  - Strongarm module: Variables.
  - Wysiwyg module: Wysiwyg profiles.
  - Wysiwyg API template plugin module: Wysiwyg templates.



Required Modules
--------------------------------------------------------------------------------

* Features - http://drupal.org/project/features



Recommended Modules
--------------------------------------------------------------------------------

* Drupal core Help



TODO
--------------------------------------------------------------------------------

- Add support for Display suite Field/Layout settings.
- Add support for Drupal core Fields for all Entities.
- Add support for Drupal core Menu links.
- Add support for Field groups.
- Add API documentation.
