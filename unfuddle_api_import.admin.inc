<?php
// $Id$

/**
 * Form for cron import.
 */
function unfuddle_api_import_cron_form() {
  $form = array();
  $form['#prefix'] = t('Use the following form to select which project\'s tickets, people, and time entries are imported during cron. CRON NOT YET WORKING! See: http://lists.drupal.org/pipermail/development/2010-July/035892.html');
  $form = $form + unfuddle_api_import_form_settings('cron');
  
  return system_settings_form($form);
}
/**
 * Form for importing manually.
 */
function unfuddle_api_import_now_form() {
  $form = array();
  $form['#prefix'] = t('Use the following form import project\'s tickets, people, and time entries NOW.');
  $form['submit'] = array(
    '#type' => 'submit',
    '#weight' => 5,
    '#value' => t('Import'),
  );
  $form = $form + unfuddle_api_import_form_settings('now');
  
  return $form;
}

/**
 * Form for Unfuddle Import settings.
 * @param type
 *   Which form is being called
 */
function unfuddle_api_import_form_settings($type) {
  $active_clients = unfuddle_api_import_projects_active();
  $form['unfuddle_api_import_' . $type . '_clients'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Clients'),
    '#options' => $active_clients,
    '#default_value' => variable_get('unfuddle_api_import_cron_clients', array()),
    '#multiple' => TRUE,
  );
  return $form;
}

/**
 *
 */
function unfuddle_api_import_now_form_submit($form_id, &$form_state) {
  $project_ids = $form_state['clicked_button']['#post']['unfuddle_api_import_now_clients'];
  if ($project_ids) {
    unfuddle_api_import_import_elements($project_ids);
  }
}
