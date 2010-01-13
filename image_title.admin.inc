<?php
/**
 * form containing available admin settings
 * 
 * @return
 * array containing the form
 */
function image_title_admin_form() {
  //define our admin form
  $form = array();
  $form['image_title_directory'] = array(
    '#title' => t('Location within default files directory to save title images'),
    '#type' => 'textfield',
    '#required' => 'true',
    '#description' => t('Important: changing the directory where title images are saved will cause all currently uploaded title images to cease to be available.'),
    '#default_value' => variable_get('image_title_directory', 'img-title'),
  );
  $form['submit'] = array(
    '#value' => 'Save settings',
    '#type' => 'submit',
  );
  return $form;
}

/**
 * validate function to check user-entered data from the admin form
 */
function image_title_admin_form_validate($form_id, $form_state) {
  $fullpath = file_directory_path().'/'.$form_state['values']['image_title_directory'];
  file_check_directory($fullpath, 0, 'image_title_directory');
}

/**
 * submit function sets variables for this module:
 */
function image_title_admin_form_submit($form_id, $form_state) {
  //save the variables
  variable_set('image_title_directory', $form_state['values']['image_title_directory']);
  drupal_set_message(t('Settings saved.'));
}
