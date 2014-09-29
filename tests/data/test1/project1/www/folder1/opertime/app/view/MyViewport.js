/*
 * File: app/view/MyViewport.js
 *
 * This file was generated by Sencha Architect version 3.1.0.
 * http://www.sencha.com/products/architect/
 *
 * This file requires use of the Ext JS 5.0.x library, under independent license.
 * License of Sencha Architect does not include license for Ext JS 5.0.x. For more
 * details see http://www.sencha.com/license or contact license@sencha.com.
 *
 * This file will be auto-generated each and everytime you save your project.
 *
 * Do NOT hand edit this file.
 */

Ext.define('opertime.view.MyViewport', {
    extend: 'Ext.container.Viewport',
    alias: 'widget.myviewport',

    requires: [
        'opertime.view.MyViewportViewModel',
        'Ext.panel.Panel',
        'Ext.form.field.Date',
        'Ext.form.field.ComboBox',
        'Ext.button.Button'
    ],

    viewModel: {
        type: 'myviewport'
    },

    layout: {
        type: 'vbox',
        align: 'stretch'
    },
    items: [
        {
            xtype: 'panel',
            title: 'Запрос',
            layout: {
                type: 'vbox',
                align: 'stretch'
            },
            items: [
                {
                    xtype: 'container',
                    layout: {
                        type: 'hbox',
                        align: 'stretch',
                        padding: 7
                    },
                    items: [
                        {
                            xtype: 'datefield',
                            fieldLabel: 'Период с',
                            labelWidth: 60,
                            value: '01.09.2014',
                            format: 'd.m.Y'
                        },
                        {
                            xtype: 'container',
                            width: 60
                        },
                        {
                            xtype: 'datefield',
                            fieldLabel: 'по',
                            labelWidth: 30,
                            value: '30.09.2014',
                            format: 'd.m.Y'
                        },
                        {
                            xtype: 'container',
                            width: 60
                        }
                    ]
                },
                {
                    xtype: 'container',
                    layout: {
                        type: 'hbox',
                        align: 'stretch',
                        padding: 7
                    },
                    items: [
                        {
                            xtype: 'combobox',
                            width: 460,
                            fieldLabel: 'Операторы',
                            labelWidth: 150,
                            editable: false,
                            displayField: 'name',
                            forceSelection: true,
                            multiSelect: true,
                            store: 'OperatorFilters',
                            valueField: 'sql'
                        }
                    ]
                },
                {
                    xtype: 'container',
                    layout: {
                        type: 'hbox',
                        align: 'stretch',
                        padding: 7
                    },
                    items: [
                        {
                            xtype: 'combobox',
                            width: 460,
                            fieldLabel: 'Сформировать графики',
                            labelWidth: 150,
                            editable: false,
                            displayField: 'name',
                            multiSelect: true,
                            queryMode: 'local',
                            store: 'ResultFields',
                            valueField: 'value'
                        },
                        {
                            xtype: 'container',
                            width: 33
                        },
                        {
                            xtype: 'button',
                            width: 100,
                            text: 'Сформировать'
                        }
                    ]
                }
            ]
        },
        {
            xtype: 'container',
            flex: 1
        }
    ]

});