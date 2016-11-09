package jlppc.regimys.creator.pokemon;

import javax.swing.JComboBox;
import javax.swing.JLabel;

import jlppc.regimys.objects.items.Item;

public class E_TradeItemDialog extends EvolutionDialog {
	JComboBox<Item> comboBoxItem;

	public E_TradeItemDialog() {
		super();
		JLabel lblItem = new JLabel("Item");
		lblItem.setBounds(12, 39, 70, 15);
		getContentPane().add(lblItem);
		
		comboBoxItem = new JComboBox<Item>();
		for(Item item : Item.itemList){
			comboBoxItem.addItem(item);
		}
		comboBoxItem.setBounds(113, 34, 175, 24);
		getContentPane().add(comboBoxItem);
	}
}
