<?php
// $Id$
/**
 * @file
 *   Describes our data to views and defines handlers and plugins.
 */

/**
 * Implementation of hook_views_data().
 *
 * Exposes unfuddle data to the views system.
 */
function unfuddle_api_import_views_data() {
  $data['unfuddle_api_import_tickets']['table']['group']  = t('Unfuddle Tickets Data');
  $data['unfuddle_api_import_tickets']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Unfuddle Ticket'),
    'help' => t('Tickets from Unfuddle.'),
  );
  $data['unfuddle_api_import_projects']['table']['group']  = t('Unfuddle Projects Data');
  $data['unfuddle_api_import_projects']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Unfuddle Projects'),
    'help' => t('Projects from Unfuddle.'),
  );
  $data['unfuddle_api_import_time']['table']['group']  = t('Unfuddle Time Data');
  $data['unfuddle_api_import_time']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Unfuddle Time'),
    'help' => t('Time from tickets from Unfuddle.'),
  );
  $data['unfuddle_api_import_people']['table']['group']  = t('Unfuddle People Data');
  $data['unfuddle_api_import_people']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Unfuddle People'),
    'help' => t('People from Unfuddle.'),
  );
  $data['unfuddle_api_import_tickets']['table']['join'] = array(
    'unfuddle_api_import_time' => array(
      'left_field' => 'ticket_id',
      'field' => 'id',
      'type' => 'LEFT',
    ),
    'unfuddle_api_import_projects' => array(
      'left_field' => 'id',
      'field' => 'project_id',
      'type' => 'LEFT',
    ),
    'unfuddle_api_import_people' => array(
      'left_field' => 'id',
      'field' => 'person_id',
    ),
  );
  
  /************** TICKETS COLUMNS *******************/ 
  $data['unfuddle_api_import_tickets']['id'] = array(
    'title' => t('Ticket id'),
    'help' => t('id for an Unfuddle Ticket.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'unfuddle_api_import_time',
      'base field' => 'ticket_id',
      'handler' => 'views_handler_relationship',
      'label' => t('Unfuddle Time'),
    ),
  );
  $data['unfuddle_api_import_tickets']['project_id'] = array(
    'title' => t('Project id'),
    'help' => t('Project id for an Unfuddle Ticket.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'unfuddle_api_import_projects',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Unfuddle Projects'),
    ),
  );
  $data['unfuddle_api_import_tickets']['summary'] = array(
    'title' => t('Summary (ie Title)'),
    'help' => t('Title of an Unfuddle Ticket.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['unfuddle_api_import_tickets']['description'] = array(
    'title' => t('Desciption'),
    'help' => t('Description of an Unfuddle Ticket.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['unfuddle_api_import_tickets']['status'] = array(
    'title' => t('Status'),
    'help' => t('Status of an Unfuddle Ticket.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['unfuddle_api_import_tickets']['resolution'] = array(
    'title' => t('Resolution'),
    'help' => t('Resolution of an Unfuddle Ticket.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  /************** PROJECTS COLUMNS *******************/ 
  $data['unfuddle_api_import_projects']['id'] = array(
    'title' => t('Project id'),
    'help' => t('Project id for an Unfuddle Project.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['unfuddle_api_import_projects']['title'] = array(
    'title' => t('Project Title'),
    'help' => t('Title of an Unfuddle Project.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  /************** TIME COLUMNS *******************/ 
  $data['unfuddle_api_import_time']['id'] = array(
    'title' => t('Time Entry id'),
    'help' => t('id for an Unfuddle Time Entry.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['unfuddle_api_import_time']['hours'] = array(
    'title' => t('Hours'),
    'help' => t('hours for an Unfuddle Time entry.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['unfuddle_api_import_time']['date'] = array(
    'title' => t('Date'),
    'help' => t('Date for an Unfuddle Time entry.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['unfuddle_api_import_time']['description'] = array(
    'title' => t('Description'),
    'help' => t('Description for an Unfuddle Time entry.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['unfuddle_api_import_time']['person_id'] = array(
    'title' => t('Person'),
    'help' => t('Person for an Unfuddle Time entry.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'unfuddle_api_import_people',
      'base field' => 'id',
      'handler' => 'views_handler_relationship',
      'label' => t('Unfuddle Person'),
    ),
  );
  /************** PEOPLE COLUMNS *******************/ 
  $data['unfuddle_api_import_people']['first_name'] = array(
    'title' => t('First Name'),
    'help' => t('First Name for an Unfuddle Person.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['unfuddle_api_import_people']['last_name'] = array(
    'title' => t('Last Name'),
    'help' => t('Last Name for an Unfuddle Person.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}

